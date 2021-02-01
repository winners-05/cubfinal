# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sel-fcht <sel-fcht@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/29 16:58:08 by sel-fcht          #+#    #+#              #
#    Updated: 2021/01/31 16:54:33 by sel-fcht         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRC = main.c utils3.c rout.c texture3d.c rout2.c map_funct2.c map_funct.c needed.c textures.c errors.c libft/ft_strncmp.c utils2.c gnl/get_next_line.c  gnl/get_next_line_utils.c  map_utils.c  yssla7o.c   raycasting.c read_map_line.c intialize.c

NAME  = cub3D
all : $(NAME)

$(NAME):
	gcc -Wall -Werror -Wextra -lmlx -framework OpenGL -framework Appkit -g -o cub3D $(SRC)

bonus :
	gcc -Wall -Werror -Wextra -lmlx -framework OpenGL -framework Appkit  -o cub3D  $(SRC)

clean:
	rm -rf *.o 
fclean : clean 
	rm -f $(NAME)

re: fclean all