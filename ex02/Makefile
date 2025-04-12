# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: drhaouha <drhaouha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/02 11:40:52 by drhaouha          #+#    #+#              #
#    Updated: 2025/04/12 21:02:45 by drhaouha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BLUE			:= \033[0;34m
GREEN			:= \033[0;32m
ORANGE			:= \033[0;33m
RED				:= \033[0;31m
NC				:= \033[0m

CPP				:= c++

CFLAGS			:= -Wall -Werror -Wextra -std=c++98

NAME			:= account

SRCS			:= Account.cpp tests.cpp


DEFAULT_LOG		= 19920104_091532.log
LOG				= 1234.log

OBJS			= ${SRCS:.cpp=.o}

%.o: %.cpp
			@${CPP} ${CFLAGS} -c $< -o $@
			@echo "[${BLUE}${NAME}${NC}] : $@ created${NC}"

${NAME}: ${OBJS}
			@${CPP} ${CFLAGS} ${OBJS} -o $@
			@echo "[${GREEN}${NAME}${NC}] : Executable $@ created.${NC}"

all: ${NAME}

clean:
			@rm -f ${OBJS}
			@rm -f ${LOG} ${DEFAULT_LOG}
			@echo "[${ORANGE}${NAME}${NC}] : Objects removed.${NC}"

fclean: clean
			@rm -f ${NAME}
			@echo "[${RED}${NAME}${NC}] : Executable removed${NC}"

test: ${LOG} ${DEFAULT_LOG}
			@bash -c 'diff <(cut -c18- ${LOG}) <(cut -c18- ${DEFAULT_LOG}) || true'

${LOG}: ${NAME} 
			@./${NAME} > ${LOG}

${DEFAULT_LOG}:
			@echo "[${RED}${NAME}${NC}] : Log file not found, downloading it.${NC}"
			@wget https://cdn.intra.42.fr/document/document/31576/19920104_091532.log

re: fclean all

.PHONY:		fclean clean re all