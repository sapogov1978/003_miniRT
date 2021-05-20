/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brattles <brattles@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 02:40:42 by brattles          #+#    #+#             */
/*   Updated: 2021/05/10 20:36:59 by brattles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <unistd.h>
# include <math.h>
# include <stdlib.h>
# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include "mlx.h"
# include "defines.h"
# include "libft.h"
# include "get_next_line.h"
# include <stdbool.h>

typedef struct s_mlx		t_mlx;
typedef struct s_win		t_win;
typedef struct s_img		t_img;
typedef struct s_scn		t_scn;
typedef struct s_cmrs		t_cmrs;
typedef struct s_lgts		t_lgts;
typedef struct s_geom		t_geom;
typedef struct s_ray		t_ray;
typedef struct s_hit		t_hit;
typedef struct s_vec		t_vec;
typedef struct s_basis		t_basis;
typedef enum e_geom_type	t_geom_type;
typedef t_vec				t_color;

enum	e_geom_type
{
	E_PLANE,
	E_SPHERE,
	E_SQUARE,
	E_TRIANGLE,
	E_CYLINDER,
	E_GEOM_TOTAL
};

/* Coordinates structure */
struct	s_vec {
	double	x;
	double	y;
	double	z;
};

/* Cameras basis structure */
struct	s_basis {
	t_vec	xaxis;
	t_vec	yaxis;
	t_vec	zaxis;
};

/* Cameras structure. Includes: Camera point, direction of view and field *
 * of view                                                                */
struct	s_cmrs {
	t_vec	origin;
	t_vec	direction;
	int		fov;
	t_basis	basis;
	t_cmrs	*next;
};

/* Lights structure. Includes: Light point, brightness and color */
struct	s_lgts {
	t_vec			origin;
	double			brightness;
	t_color			color;
	t_lgts			*next;
};

/* Rays structure. Includes: ray origin point and ray direction */
struct	s_ray {
	t_vec			origin;
	t_vec			dir;
};

/* Hitpoints structure. Includes: pointer to geometry, distance from ray *
 * origin, normale at point, color at point                              */
struct	s_hit {
	t_geom			*geom;
	t_vec			point;
	t_vec			normal;
	double			dstn;
	t_color			color;
};

/* Geometry structure. Includes: All geometry objects data, intersects with *
 * rays from camera and function to calculate hitpoints                     */
struct	s_geom {
	t_geom_type		type;
	bool			(*intersect)(const t_geom *geom, const t_ray *ray, \
					t_hit *hit);
	t_ray			ray;
	t_hit			hit;
	int				id;
	t_vec			origin;
	t_vec			normal;
	t_color			color;
	double			diameter;
	double			height;
	double			side;
	t_vec			vertex1;
	t_vec			vertex2;
	t_vec			vertex3;
	t_geom			*next;
};

/* Window structure. Includes: Size of screen, Size from RT file *
 * Calculated size of window to open                             */
struct	s_win {
	void	*ptr;
	size_t	x_res_rt;
	size_t	y_res_rt;
	int		x_res;
	int		y_res;
	int		max_x_size;
	int		max_y_size;
};

/* Image structure. Includes: Bit depth, Color coding sequence, *
 * all pixels data                                              */
struct	s_img {
	void	*ptr;
	void	*data;
	int		bpp;
	int		endian;
	int		size_line;
};

/* Scene structure. Includes: Lights, Cameras and Geometry data */
struct	s_scn {
	char	*scn_name;
	double	amb_brightness;
	t_color	amb_color;
	int		lights_total;
	int		geom_total;
	t_cmrs	*cmrs;
	t_lgts	*lgts;
	t_geom	*geom;
};

/* General structure. Includes: Window, Image and Scene to be rendered data */
struct	s_mlx {
	void	*ptr;
	int		save_flag;
	int		save_fd;
	t_win	win;
	t_img	img;
	t_scn	scn;
	void	(*plot)(t_mlx *minirt, int x, int y, int color);
};

int		main(int argc, char **argv);

/* general functions */
int		ft_entry_check(int argc, char **argv);
t_mlx	*ft_struct_init(char **argv);
void	ft_print_help(void);
void	ft_panic(char *msg);
int		unload(t_mlx *minirt);
int		on_keydown(int key, t_mlx *minirt);

/* parser functions */
void	ft_rtparser(int fd, t_mlx *minirt);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_split_line_qty(char **splitted);
char	*ft_get_scene_name(char **argv);
void	ft_get_resolution(t_mlx *minirt, char **splitted);
void	ft_get_ambient(t_mlx *minirt, char **splitted);
void	ft_get_cameras(t_cmrs **camera, char **splitted);
void	ft_get_lights(t_mlx *minirt, t_lgts **light, char **splitted);
void	ft_get_plane(t_scn *scn, t_geom **plane, char **splitted);
void	ft_get_sphere(t_scn *scn, t_geom **sphere, char **splitted);
void	ft_get_cylinder(t_scn *scn, t_geom **cylinder, char **splitted);
void	get_cy_point_normal(const t_geom *cy, const t_ray *ray, t_hit *hit);
bool	hit_norminette_crutch(const t_geom *cy, const t_ray *ray, \
									double d, t_hit *hit);
bool	cy_d_exp(const t_geom *cy, const t_ray *ray, double sq, double d);
void	ft_get_square(t_scn *scn, t_geom **square, char **splitted);
void	ft_get_triangle(t_scn *scn, t_geom **triangle, char **splitted);
void	ft_get_vector(t_vec *point, char *coords);
void	ft_light_nrmlz(t_scn *scn);

/* intersects */
bool	plane_intersect(const t_geom *pl, const t_ray *ray, t_hit *hit);
bool	sphere_intersect(const t_geom *sp, const t_ray *ray, t_hit *hit);
bool	square_intersect(const t_geom *sq, const t_ray *ray, t_hit *hit);
bool	triangle_intersect(const t_geom *tr, const t_ray *ray, t_hit *hit);
bool	cylinder_intersect(const t_geom *cy, const t_ray *ray, t_hit *hit);
t_color	ft_intersect(t_mlx *minirt, t_vec ray);
bool	intersect_all(const t_scn *scn, const t_ray *ray, t_hit *hit);
bool	first_intersect(const t_scn *scn, const t_ray *ray, double max_dst);

/* math functions */
double	vec_len(t_vec vector);
t_vec	vec_summ(t_vec a, t_vec b);
t_vec	vec_diff(t_vec a, t_vec b);
t_vec	cross(t_vec a, t_vec b);
double	dot(t_vec a, t_vec b);
t_vec	vec_len_add(t_vec vector, double x);
t_vec	vec_nmlz(t_vec vector);
t_vec	vec_transfer(t_vec a, t_vec b);
t_vec	equation_variable(t_vec direction, t_vec cam_origin);
t_vec	faceforward(t_vec ray, t_vec norm);
t_basis	*basis_create(t_basis *basis, t_vec direction);
void	basis_apply(const t_basis *basis, t_vec *v);
t_vec	mltp(t_vec a, t_vec b);
t_vec	dvsn(t_vec a, double b);
float	ft_maxf(float a, float b);
float	ft_minf(float a, float b);

/* color functions */
bool	ft_is_false_color(t_color color);
int		vec_to_int(t_color c);
t_color	ft_intersect(t_mlx *minirt, t_vec ray);
int		clamp(int value, int min, int max);
double	clampf(double value, double min, double max);
t_color	find_color(t_vec intersect, t_scn *scn, t_hit *hit);
t_color	ft_mix_color(t_color color, double intensity);
t_color	mix_color(t_color a, t_color b);
t_color	rgb_add(t_color rgb1, t_color rgb2);
t_color	rgb_mult(t_color rgb1, t_color rgb2);

/* RT Functions */
void	ft_rendering(t_mlx *minirt);
void	pixel_put(t_mlx *minirt, int x, int y, int color);
void	plot(t_img *img, int x, int y, int color);
void	camera_switch(t_mlx *minirt, t_cmrs **camera);
void	save(t_mlx *minirt);

#endif
