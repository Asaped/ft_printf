SRCS	 = ft_printf.c ft_traitement.c ft_utils.c

OBJS	 = $(SRCS:.c=.o)

NAME	 = libftprintf.a

CC		 = gcc

CFLAGS	 = -Wall -Wextra -Werror

RM		 = rm -rf

all	 	 : $(NAME)

$(NAME)	 : $(OBJS)
		ar rcs $(NAME) $(OBJS)

clean	 :
		$(RM) $(OBJS)

fclean	 : clean
		$(RM) $(NAME)

re		 : fclean all

.PHONY	 : all fclean clean re
