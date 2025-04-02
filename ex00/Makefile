# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: drhaouha <drhaouha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/02 11:40:52 by drhaouha          #+#    #+#              #
#    Updated: 2025/04/02 11:49:35 by drhaouha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BLUE			:= \033[0;34m
GREEN			:= \033[0;32m
ORANGE			:= \033[0;33m
RED				:= \033[0;31m
NC				:= \033[0m

CPP				:= c++

CFLAGS			:= -Wall -Werror -Wextra -std=c++98 -g

NAME			:= megaphone

MEGAPHONE		:= megaphone.cpp

OBJ				= ${MEGAPHONE:.cpp=.o}

%.o: %.cpp
			@${CPP} ${CFLAGS} -c $< -o $@
			@echo "[${BLUE}${NAME}${NC}] : $@ created${NC}"

${NAME}: ${OBJ}
			@${CPP} ${CFLAGS} ${OBJ} -o $@
			@echo "[${GREEN}${NAME}${NC}] : Executable $@ created.${NC}"

all: ${NAME}

clean:
			@rm -f ${OBJ}
			@echo "[${ORANGE}${NAME}${NC}] : Objects removed.${NC}"

fclean: clean
			@rm -f ${NAME}
			@echo "[${RED}${NAME}${NC}] : Executable removed${NC}"

re: fclean all

.PHONY:		fclean clean re all