# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebengtss <ebengtss@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/13 11:16:00 by ebengtss          #+#    #+#              #
#    Updated: 2024/07/24 13:16:23 by ebengtss         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS 		+=	--no-print-directory

NAME			=	push_swap
NAME_BNS		=	checker

LIBFT			=	libft
LIBFT_A			=	$(LIBFT).a

CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror -I

LIBFT_DIR		=	libft
SRCS_DIR		=	srcs/
OBJS_DIR		=	objs/
INCS_DIR		=	incs
SRCS_DIR_BNS	=	srcs_bonus/
OBJS_DIR_BNS	=	objs_bonus/
INCS_DIR_BNS	=	incs_bonus

SRCS_FILES		=	main.c				\
					frees.c				\
					lookup.c			\
					median.c			\
					stack.c				\
					small_sort.c		\
					big_sort.c			\
					mooves_count.c		\
					mooves_build.c		\
					push_swap_utils.c	\
					instr_push.c		\
					instr_swap.c		\
					instr_reverse.c		\
					instr_rotate.c

SRCS_FILES_BNS	=	main_bonus.c			\
					frees_bonus.c			\
					check_bonus.c			\
					stack_bonus.c			\
					push_swap_utils_bonus.c	\
					instr_push_bonus.c		\
					instr_swap_bonus.c		\
					instr_reverse_bonus.c	\
					instr_rotate_bonus.c

SRCS			=	$(addprefix $(SRCS_DIR), $(SRCS_FILES))
OBJS			=	$(addprefix $(OBJS_DIR), $(SRCS_FILES:.c=.o))
SRCS_BNS		=	$(addprefix $(SRCS_DIR_BNS), $(SRCS_FILES_BNS))
OBJS_BNS		=	$(addprefix $(OBJS_DIR_BNS), $(SRCS_FILES_BNS:.c=.o))

DEF_COLOR		=	\033[0;39m
MAGENTA			=	\033[0;95m
GREEN			=	\033[0;92m
DEF_WEIGHT		=	\e[0m
BOLD_WEIGHT		=	\e[1m

OBJSF			=	.objs_exists
OBJSF_BNS		=	.objs_exists_bns

all				:	$(NAME)

$(NAME)			:	$(OBJS) $(LIBFT_A)
	@$(CC) -o $(NAME) $(CFLAGS) $(INCS_DIR) $(OBJS) $(LIBFT_A)
	@echo "$(BOLD_WEIGHT)[PUSH SWAP]$(DEF_WEIGHT) make: $(GREEN)OK$(DEF_COLOR)"

bonus			:	$(OBJS_BNS) $(LIBFT_A)
	@$(CC) -o $(NAME_BNS) $(CFLAGS) $(INCS_DIR_BNS) $(OBJS_BNS) $(LIBFT_A)
	@echo "$(BOLD_WEIGHT)[PUSH SWAP]$(DEF_WEIGHT) bonus: $(GREEN)OK$(DEF_COLOR)"

$(LIBFT_A)	:
	@make -C $(LIBFT_DIR)
	@mv $(LIBFT)/$(LIBFT_A) ./

$(OBJS_DIR)%.o	:	$(SRCS_DIR)%.c | $(OBJSF)
	@$(CC) $(CFLAGS) $(INCS_DIR) -c $< -o $@
	@echo "$(BOLD_WEIGHT)[PUSH SWAP]$(DEF_WEIGHT) compiling: $(MAGENTA) $< $(DEF_COLOR)"

$(OBJS_DIR_BNS)%.o	:	$(SRCS_DIR_BNS)%.c | $(OBJSF_BNS)
	@$(CC) $(CFLAGS) $(INCS_DIR_BNS) -c $< -o $@
	@echo "$(BOLD_WEIGHT)[PUSH SWAP]$(DEF_WEIGHT) compiling: $(MAGENTA) $< $(DEF_COLOR)"

$(OBJSF)	:
	@mkdir -p $(OBJS_DIR)

$(OBJSF_BNS)	:
	@mkdir -p $(OBJS_DIR_BNS)

clean			:
	@rm -rf $(OBJS_DIR)
	@rm -rf $(OBJS_DIR_BNS)
	@make clean -C $(LIBFT)
	@rm -f $(LIBFT_A)
	@echo "$(BOLD_WEIGHT)[PUSH SWAP]$(DEF_WEIGHT) clean: $(GREEN)OK$(DEF_COLOR)"

fclean			:	clean
	@rm -f $(NAME)
	@rm -f $(NAME_BNS)
	@echo "$(BOLD_WEIGHT)[PUSH SWAP]$(DEF_WEIGHT) fclean: $(GREEN)OK$(DEF_COLOR)"

re				:	fclean all

.PHONY			:	all bonus clean fclean re