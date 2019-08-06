NAME			=		fractol

INC				=		includes/

SRC_NAME		=	fractol.c draw_fractol.c keyboard.c \
					mouse.c utils1.c

SRC_PATH		=	srcs/

OBJ_NAME		=	$(SRC_NAME:.c=.o)

OBJ_PATH		=	srcs/obj/

INC_NAME		=	fractol.h f_string.h

INC_PATH		=	includes/

LIB_NAME		=	libft.a

LIB_PATH		=	libft/

LIB_INC_PATH	=	libft/includes/

LIB_INC_NAME	=	libft.h

LIB				=	$(addprefix $(LIB_PATH), $(LIB_NAME))
LIB_INC			=	$(addprefix $(LIB_INC_PATH), $(LIB_INC_NAME))
OBJ				=	$(addprefix $(OBJ_PATH), $(OBJ_NAME))
INC				=	$(addprefix $(INC_PATH), $(INC_NAME))


.PHONY:				all $(LIB_NAME) clean fclean re


all: 				$(LIB_NAME) $(NAME)

$(LIB_NAME):
						@make -C $(LIB_PATH)

$(NAME):			$(LIB) $(OBJ)
						@gcc -Wall -Wextra -Werror $(OBJ) \
						-lmlx -framework OpenGL -framework AppKit -lm \
						-L $(LIB_PATH) -lft -o $(NAME)

$(OBJ_PATH)%.o:		$(SRC_PATH)%.c $(INC) $(LIB_INC)
						@mkdir -p $(OBJ_PATH)
						@gcc -Wall -Wextra -Wextra \
						-I $(INC_PATH) -I $(LIB_INC_PATH) -o $@ -c $<

clean:
						@make -C $(LIB_PATH) fclean
						@rm -f $(OBJ)
						@rm -rf $(OBJ_PATH)

fclean:				clean
						@rm -rf $(NAME)

re:					fclean all

