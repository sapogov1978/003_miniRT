# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brattles <brattles@student.21-school.ru    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/29 20:25:41 by brattles          #+#    #+#              #
#    Updated: 2021/05/10 12:39:13 by brattles         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY:	all clean fclean re
.SUFFIXES:
.SUFFIXES: .c .o .h .d

NAME 	= libft.a

FUNCTIONS	= ft_memset.c \
			  ft_bzero.c \
			  ft_memcpy.c \
			  ft_memmove.c \
			  ft_strlen.c \
			  ft_tolower.c \
			  ft_toupper.c \
			  ft_memcmp.c \
			  ft_isalpha.c \
			  ft_isdigit.c \
			  ft_memchr.c \
			  ft_memccpy.c \
			  ft_isascii.c \
			  ft_isprint.c \
			  ft_isalnum.c \
			  ft_strlcpy.c \
			  ft_strlcat.c \
			  ft_atoi.c \
			  ft_strchr.c \
			  ft_strrchr.c \
			  ft_strncmp.c \
			  ft_strnstr.c \
			  ft_calloc.c \
			  ft_strdup.c \
			  ft_putchar_fd.c \
			  ft_putstr_fd.c \
			  ft_putendl_fd.c \
			  ft_putnbr_fd.c \
			  ft_strmapi.c \
			  ft_itoa.c \
			  ft_substr.c \
			  ft_strjoin.c \
			  ft_strtrim.c \
			  ft_split.c \
			  ft_strncpy.c \
			  ft_atof.c \
			  ft_lstnew.c \
			  ft_lstlast.c \
			  ft_lstadd_back.c \
			  ft_lstadd_front.c \
			  ft_lstdelone.c \
			  ft_lstclear.c \
			  get_next_line.c \
			  get_next_line_utils.c \
			  ft_isspace.c \
			  ft_memclean.c

OBJ		= $(patsubst %.c, %.o, $(FUNCTIONS))
D_FILE  = $(patsubst %.c, %.d, $(FUNCTIONS))

CFLAGS 	= -Wall -Wextra -Werror
CC		= gcc

all: $(NAME)

$(NAME): $(OBJ)
	ar -rc $(NAME) $?
	ranlib $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I. -c $< -o $@ -MD

include $(wildcard $(D_FILE))

clean:
	rm -f $(OBJ)
	rm -f $(D_FILE)
fclean: clean
	rm -f $(NAME)
re: fclean all