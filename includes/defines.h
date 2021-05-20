/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brattles <brattles@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 21:36:26 by brattles          #+#    #+#             */
/*   Updated: 2021/05/09 19:29:56 by brattles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# define BUFFER_SIZE 4096

# define KEY_DOWN 2

# ifdef __APPLE__
#  define DESTROY 17
#  define KEY_ESC 53
#  define KEY_UP_ARW 126
#  define KEY_LEFT_ARW 123
#  define KEY_DOWN_ARW 125
#  define KEY_RIGHT_ARW 124
#  define KEY_1 18
#  define KEY_2 19
#  define KEY_3 20
#  define KEY_4 21
#  define KEY_5 23
#  define KEY_6 22
#  define KEY_7 26
#  define KEY_8 28
#  define KEY_9 25
#  define KEY_0 29
#  define KEY_W 13
#  define KEY_A 0
#  define KEY_S 1
#  define KEY_D 2
#  define KEY_Q 12
#  define KEY_E 14
#  define KEY_NUM_1 83
#  define KEY_NUM_2 84
#  define KEY_NUM_3 85
#  define KEY_NUM_4 86
#  define KEY_NUM_5 87
#  define KEY_NUM_6 88
#  define KEY_NUM_7 89
#  define KEY_NUM_8 91
#  define KEY_NUM_9 92
#  define KEY_NUM_0 82
#  define KEY_NUM_PLUS 69
#  define KEY_NUM_MINUS 78
#  define KEY_NUM_MTPL 67
#  define KEY_NUM_DVD 75
#  define KEY_LSHIFT 56
#  define KEY_RSHIFT 56
#  define KEY_LCTRL 59
#  define KEY_RCTRL 59
#  define KEY_LOPTIONS 58
#  define KEY_ROPTIONS 58
#  define KEY_TAB 48
#  define KEY_APOS 50

# elif __linux__
#  define DESTROY 33
#  define KEY_ESC 65307
#  define KEY_UP_ARW 65362
#  define KEY_LEFT_ARW 65361
#  define KEY_DOWN_ARW 65364
#  define KEY_RIGHT_ARW 65363
#  define KEY_1 49
#  define KEY_2 50
#  define KEY_3 51
#  define KEY_4 52
#  define KEY_5 53
#  define KEY_6 54
#  define KEY_7 55
#  define KEY_8 56
#  define KEY_9 57
#  define KEY_0 48
#  define KEY_W 119
#  define KEY_A 97
#  define KEY_S 115
#  define KEY_D 100
#  define KEY_Q 113
#  define KEY_E 101
#  define KEY_NUM_1 65513
#  define KEY_NUM_2 65433
#  define KEY_NUM_3 65435
#  define KEY_NUM_4 65430
#  define KEY_NUM_5 65437
#  define KEY_NUM_6 65432
#  define KEY_NUM_7 65429
#  define KEY_NUM_8 65431
#  define KEY_NUM_9 65434
#  define KEY_NUM_0 65438
#  define KEY_NUM_PLUS 65451
#  define KEY_NUM_MINUS 65453
#  define KEY_NUM_MTPL 65450
#  define KEY_NUM_DVD 65455
#  define KEY_LSHIFT 65505
#  define KEY_RSHIFT 65506
#  define KEY_LCTRL 65507
#  define KEY_RCTRL 65508
#  define KEY_LOPTIONS 65513
#  define KEY_ROPTIONS 65514
#  define KEY_TAB 65289
#  define KEY_APOS 96
# endif

# ifdef __linux__
#  define M_E		2.7182818284590452354	/* e */
#  define M_LOG2E	1.4426950408889634074	/* log_2 e */
#  define M_LOG10E	0.43429448190325182765	/* log_10 e */
#  define M_LN2		0.69314718055994530942	/* log_e 2 */
#  define M_LN10		2.30258509299404568402	/* log_e 10 */
#  define M_PI		3.14159265358979323846	/* pi */
#  define M_PI_2		1.57079632679489661923	/* pi/2 */
#  define M_PI_4		0.78539816339744830962	/* pi/4 */
#  define M_1_PI		0.31830988618379067154	/* 1/pi */
#  define M_2_PI		0.63661977236758134308	/* 2/pi */
#  define M_2_SQRTPI	1.12837916709551257390	/* 2/sqrt(pi) */
#  define M_SQRT2	1.41421356237309504880	/* sqrt(2) */
#  define M_SQRT1_2	0.70710678118654752440	/* 1/sqrt(2) */
# endif

# define EPSILON 0.001

#endif
