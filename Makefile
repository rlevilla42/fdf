# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rlevilla <rlevilla@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/16 02:35:28 by rlevilla          #+#    #+#              #
#    Updated: 2023/05/25 01:07:16 by rlevilla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.c parsing.c draw_line.c init.c my_mlx_pixel_put.c set_env.c hook.c free.c
OBJS	= ${SRCS:.c=.o}

LIBFT = libft

// MEMEORY_FLAG = -fsanitize=address

CFLAGS	= gcc -Wall -Wextra -Werror

RM	= rm -f

OPTIONS	= -I

NAME	= fdf

all:	${NAME}

$(NAME): $(OBJS)
	$(MAKE) -C minilibx_macos/
	$(MAKE) -C libft/
	$(CFLAGS) $(MEMORY_FLAG) $(OBJS) -L./libft/ -lft -L./minilibx_macos -lmlx -framework OpenGL -framework AppKit -o $(NAME)

.c.o:
			${CFLAGS} -I./libft -I./minilibx_macos -c $< -o ${<:.c=.o}

${LIBFT}:
		${MAKE} -C /libft/

clean:
			${MAKE} -C libft/ clean
			${MAKE} -C minilibx_macos/ clean
			${RM} ${OBJS}

fclean:	clean
				${RM} ${NAME}
				${MAKE} -C libft/ fclean
				${MAKE} -C minilibx_macos/ clean
re:	fclean all

.PHONY: clean fclean all re
