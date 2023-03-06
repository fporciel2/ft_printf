# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fporciel <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/06 13:39:47 by fporciel          #+#    #+#              #
#    Updated: 2023/03/06 14:02:27 by fporciel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re
.DEFAULT_GOAL := $(NAME)
NAME := libftprintf.a
SRCS := $(shell find . -type f -name "ft_*.c")
HEADERS := $(shell find . -type f -name "libft*.h")
OBJS := $(patsubst %.c, %.o, $(SRCS))
CC := gcc
CFLAGS := -Wall -Wextra -Werror -c

$(NAME): $(OBJS) $(HEADERS)
	ar rcs $@ $^

all: $(NAME)

$(OBJS): $(SRCS) $(HEADERS)
	$(CC) $(CFLAGS) $^

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

