# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sel-fcht <sel-fcht@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/29 16:58:08 by sel-fcht          #+#    #+#              #
#    Updated: 2021/02/14 17:22:14 by sel-fcht         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRC = main.c treat.c sprite.c bmp.c read_map_line2.c get_next_line.c get_next_line_utils.c utils.c utils3.c rout.c texture3d.c rout2.c  map_funct.c needed.c textures.c errors.c ft_strncmp.c utils2.c  map_utils.c  yssla7o.c   raycasting.c read_map_line.c intialize.c
NAME  = cub3D
DBG   = -g -fsanitize=address
CFLGS = -Wall -Werror -Wextra
NAME2 = Cub3D
all : $(NAME)

$(NAME): $(SRC)
	gcc  $(CFLGS) -lmlx -framework OpenGL -framework Appkit -o cub3D $(SRC) -O3

bonus : $(NAME2)
$(NAME2) : $(SRC)
	gcc $(CFLGS) -lmlx -framework OpenGL -framework Appkit -o cub3D $(SRC) -O3

clean:
	rm -rf *.o

fclean : clean 
	rm -f $(NAME)
	rm -rf screenshot.bmp
	rm -rf cub3D

re: fclean all

norm :
	norminette *.c *.h