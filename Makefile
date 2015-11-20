# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmathe <dmathe@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/12 13:11:10 by dmathe            #+#    #+#              #
#    Updated: 2015/11/20 15:17:03 by dmathe           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = good.c position.c push.c push_swap.c ra.c rra.c sa.c sort.c list_print.c

OBJS =		$(SRCS:.c=.o)

INCLUDES =	-I libft/ \
			-I includes/

LIBS =		-L libft/ -lft \

FLAGS =		-g -Wall -Wextra -Werror


$(NAME):	$(OBJS)
	@make -C libft/ fclean
	@make -C libft/
	@echo "Create binary"
	@gcc -o $(NAME) $(OBJS) $(LIBS)
	@echo "Complitation ok"

$(OBJS): %.o: %.c
	@gcc $(FLAGS) $(INCLUDES) -c $< -o $@

all:		$(NAME)

clean:
	rm -f	$(OBJS)

fclean: clean
	rm -f	$(NAME)

re: fclean all

.PHONY:	 all clean fclean re
