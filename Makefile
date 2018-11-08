# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dde-jesu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 16:01:17 by dde-jesu          #+#    #+#              #
#    Updated: 2018/11/08 17:00:17 by dde-jesu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a
CFLAGS=-Wall -Werror -Wextra
include srcs.mk
OBJS=$(SRCS:.c=.o)

all: $(NAME)

$(OBJS): libft.h Makefile srcs.mk

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean $(NAME)

proto:
	@grep -E "[^ ]+\t+\*?ft_[^ \(]+\(" -h *.c | sed 's/$$/;/'
