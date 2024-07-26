# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebengtss <ebengtss@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/13 11:16:00 by ebengtss          #+#    #+#              #
#    Updated: 2024/07/26 16:04:09 by ebengtss         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS 			+=	--no-print-directory

NAME				=	push_swap
NAME_BONUS			=	checker

LIBFT				=	libft
LIBFT_A				=	$(LIBFT).a

CC					=	cc
CFLAGS				=	-Wall -Wextra -Werror -I

LIBFT_DIR			=	libft
SRCS_DIR			=	srcs/
OBJS_DIR			=	objs/
INCS_DIR			=	incs
SRCS_DIR_BONUS		=	srcs_bonus/
OBJS_DIR_BONUS		=	objs_bonus/
INCS_DIR_BONUS		=	incs_bonus

SRCS_FILES			=	main.c					\
						frees.c					\
						lookup.c				\
						median.c				\
						stack.c					\
						small_sort.c			\
						big_sort.c				\
						mooves_count.c			\
						mooves_build.c			\
						push_swap_utils.c		\
						instr_push.c			\
						instr_swap.c			\
						instr_reverse.c			\
						instr_rotate.c

SRCS_FILES_BONUS	=	main_bonus.c			\
						frees_bonus.c			\
						check_bonus.c			\
						stack_bonus.c			\
						instr_push_bonus.c		\
						instr_swap_bonus.c		\
						instr_reverse_bonus.c	\
						instr_rotate_bonus.c

OBJS				=	$(addprefix $(OBJS_DIR), $(SRCS_FILES:.c=.o))
OBJS_BONUS			=	$(addprefix $(OBJS_DIR_BONUS), $(SRCS_FILES_BONUS:.c=.o))

DEF_COLOR			=	\033[0;39m
MAGENTA				=	\033[0;95m
GREEN				=	\033[0;92m
DEF_STYLE			=	\e[0m
BOLD_OPACITY		=	\e[1m\e[2m
RESET_LINE			=	\033[A\033[K

OBJSF				=	.objs_exists
OBJSF_BONUS			=	.objs_bonus_exists

all				:	$(NAME)
bonus			:	$(NAME_BONUS)

$(NAME)			:	$(LIBFT_A) $(OBJS)
	@echo "$(RESET_LINE)$(BOLD_OPACITY)[ PUSH_SWAP ]$(DEF_STYLE)	compiling:	$(GREEN) ✔ $(DEF_COLOR)"
	@$(CC) -o $(NAME) $(CFLAGS) $(INCS_DIR) $(OBJS) $(LIBFT_A)
	@echo "$(BOLD_OPACITY)[ PUSH_SWAP ]$(DEF_STYLE)	make:		$(GREEN) ✔ $(DEF_COLOR)"

$(NAME_BONUS)	:	$(LIBFT_A) $(OBJS_BONUS)
	@echo "$(RESET_LINE)$(BOLD_OPACITY)[ PUSH_SWAP ]$(DEF_STYLE)	compiling:	$(GREEN) ✔ $(DEF_COLOR)"
	@$(CC) -o $(NAME_BONUS) $(CFLAGS) $(INCS_DIR_BONUS) $(OBJS_BONUS) $(LIBFT_A)
	@echo "$(BOLD_OPACITY)[ PUSH_SWAP ]$(DEF_STYLE)	bonus:		$(GREEN) ✔ $(DEF_COLOR)"

$(LIBFT_A)	:
	@make -C $(LIBFT_DIR)
	@mv $(LIBFT)/$(LIBFT_A) ./

$(OBJS_DIR)%.o	:	$(SRCS_DIR)%.c | $(OBJSF)
	@$(CC) $(CFLAGS) $(INCS_DIR) -c $< -o $@
	@echo "$(RESET_LINE)$(BOLD_OPACITY)[ PUSH_SWAP ]$(DEF_STYLE)	compiling:	$(GREEN) $< $(DEF_COLOR)"

$(OBJS_DIR_BONUS)%.o	:	$(SRCS_DIR_BONUS)%.c | $(OBJSF_BONUS)
	@$(CC) $(CFLAGS) $(INCS_DIR_BONUS) -c $< -o $@
	@echo "$(RESET_LINE)$(BOLD_OPACITY)[ PUSH_SWAP ]$(DEF_STYLE)	compiling:	$(GREEN) $< $(DEF_COLOR)"

$(OBJSF)	:
	@echo "$(BOLD_OPACITY)[ PUSH_SWAP ]$(DEF_STYLE)	nothing to do"
	@mkdir -p $(OBJS_DIR)

$(OBJSF_BONUS)	:
	@echo "$(BOLD_OPACITY)[ PUSH_SWAP ]$(DEF_STYLE)	nothing to do"
	@mkdir -p $(OBJS_DIR_BONUS)

clean			:
	@rm -rf $(OBJS_DIR)
	@rm -rf $(OBJS_DIR_BONUS)
	@make clean -C $(LIBFT)
	@rm -f $(LIBFT_A)
	@echo "$(BOLD_OPACITY)[ PUSH_SWAP ]$(DEF_STYLE)	clean:		$(GREEN) ✔ $(DEF_COLOR)"

fclean			:	clean
	@rm -f $(NAME)
	@rm -f $(NAME_BONUS)
	@echo "$(BOLD_OPACITY)[ PUSH_SWAP ]$(DEF_STYLE)	fclean:		$(GREEN) ✔ $(DEF_COLOR)"

re				:	fclean all

.PHONY			:	all bonus clean fclean re