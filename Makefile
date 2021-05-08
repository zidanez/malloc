# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fnancy <fnancy@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/07 12:53:07 by fnancy            #+#    #+#              #
#    Updated: 2021/05/07 15:08:19 by fnancy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

NAME = libft_malloc.so

HOSTLIB = libft_malloc_$(HOSTTYPE).so

SRC =	block.c \
		free.c \
		getter.c \
		heap.c \
		malloc.c \
		printer_helper.c \
		printer.c \
		realloc.c

SRCDIR = src/

OBJDIR = objs

CFLAGS = -Wall -Wextra -g -Werror

LDFLAGS = -shared

DEP = Libft/include/libft.h include/malloc.h

CC = gcc

OBJ = $(addprefix $(OBJDIR)/, $(SRC:.c=.o))

LIB = -L./Libft -lft

INCL = -I Libft/include -I include

LIB_PATH = Libft/

LIBS = libft.a
############################## COLORS ##########################################

RED = "\033[31m"
GREEN = "\033[32m"
YELLOW = "\033[33m"
BLUE = "\033[34m"
PINK = "\033[35m"
AQUA = "\033[36m"
GREY = "\033[37m"
UNDERLINE = "\033[4m"
ESCN = "\033[0m"

##############################        ###########################################

all: ${LIBS} ${NAME}
	@echo ${GREEN}Success"   "[${NAME}]${ESCN}

${NAME}: ${HOSTLIB}
	@echo ${GREY}Linking"   "[${HOSTLIB}]...${ESCN}
	@ln -fs ${HOSTLIB} ${NAME}

${HOSTLIB}: ${OBJ} ${DEP} ${LIB_PATH}/libft.a
	@echo ${BLUE}Compiling [${HOSTLIB}]...${ESCN}
	@${CC} ${LDFLAGS} ${LIB} ${INCL} -o $@ ${OBJ}

${OBJDIR}/%.o: ${SRCDIR}%.c ${DEP} ${LIB_PATH}/libft.a
	@echo ${AQUA}Compiling [$@]...${ESCN}
	@/bin/mkdir -p ${OBJDIR}
	@${CC} ${CFLAGS} ${INCL} -c -o $@ $<

${LIBS}:
	@make -C $(LIB_PATH)

clean:
	@echo ${RED}Cleaning"  "[libft objs]...${ESCN}
	@make clean -C $(LIB_PATH)
	@echo ${RED}Cleaning"  "[objs]...${ESCN}
	@/bin/rm -Rf ${OBJDIR}

fclean: clean
	@make fclean -C $(LIB_PATH)
	@echo ${RED}Cleaning"  "[${NAME}]...${ESCN}
	@/bin/rm -f ${NAME}
	@/bin/rm -f ${HOSTLIB}

re: fclean all

.PHONY: all clean fclean re