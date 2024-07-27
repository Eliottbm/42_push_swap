# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebengtss <ebengtss@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/13 11:16:00 by ebengtss          #+#    #+#              #
#    Updated: 2024/07/27 21:38:24 by ebengtss         ###   ########.fr        #
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
						position.c				\
						stack.c					\
						small_sort.c			\
						big_sort.c				\
						mooves_count.c			\
						mooves_build.c			\
						push_swap_utils.c		\
						push_swap_utils2.c		\
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
	@echo "$(RESET_LINE)$(BOLD_OPACITY)[ PUSH_SWAP ]$(DEF_STYLE)	bonus compiling:$(GREEN) ✔ $(DEF_COLOR)"
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
	@echo "$(RESET_LINE)$(BOLD_OPACITY)[ PUSH_SWAP ]$(DEF_STYLE)	bonus compiling:$(GREEN) $< $(DEF_COLOR)"

$(OBJSF)	:
	@echo "$(BOLD_OPACITY)[ PUSH_SWAP ]$(DEF_STYLE)	nothing to do"
	@mkdir -p $(OBJS_DIR)

$(OBJSF_BONUS)	:
	@echo "$(BOLD_OPACITY)[ PUSH_SWAP ]$(DEF_STYLE)	bonus nothing to do"
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

runtest			:	all bonus
	@echo "$(BOLD_OPACITY)[ PUSH_SWAP ]$(DEF_STYLE)	running test ..."
	@if [ -z "$(ELM)" ]; then echo "$(BOLD_OPACITY)[ PUSH_SWAP ]$(DEF_STYLE)	Please provide the number of elements to sort (ex: EML=100)"; exit 1; fi
	@if [ -z "$(RUN)" ]; then echo "$(BOLD_OPACITY)[ PUSH_SWAP ]$(DEF_STYLE)	Please provide the number of test to run (ex: RUN=500)"; exit 1; fi
	@if [ -z "$(MAX)" ]; then echo "$(BOLD_OPACITY)[ PUSH_SWAP ]$(DEF_STYLE)	Please provide the number of max mooves allowed (ex: MAX=700)"; exit 1; fi
	@echo " ";
	@TOTAL_MOVES=0; 																											\
	SUCCESS_COUNT=0; 																											\
	MIN_MOVES=999999; 																											\
	MAX_MOVES=0; 																												\
	for i in $$(seq 1 $(RUN)); do																								\
	NUMBERS=$$(shuf -i 1-1000 -n $(ELM) | tr '\n' ' ');																			\
	ARG="$$NUMBERS";																											\
	RESULT=$$(./$(NAME) $$ARG | ./$(NAME_BONUS) $$ARG);																			\
	if [ "$$RESULT" != "OK" ]; then																								\
		echo "$(BOLD_OPACITY)[ PUSH_SWAP ]$(DEF_STYLE)	Le tri n'a pas réussi pour le test $$i";								\
		continue;																												\
	fi;																															\
	MOVES=$$(./$(NAME) $$ARG | wc -l);																							\
	TOTAL_MOVES=$$((TOTAL_MOVES + MOVES));																						\
	echo "$(RESET_LINE)$(BOLD_OPACITY)[ PUSH_SWAP ]$(DEF_STYLE)	Test $$i: $$MOVES coups";										\
	if [ $$MOVES -lt $$MIN_MOVES ]; then																						\
		MIN_MOVES=$$MOVES;																										\
	fi;																															\
	if [ $$MOVES -gt $$MAX_MOVES ]; then																						\
		MAX_MOVES=$$MOVES;																										\
	fi;																															\
	if [ $$MOVES -lt $(MAX) ]; then																								\
		SUCCESS_COUNT=$$((SUCCESS_COUNT + 1));																					\
	fi;																															\
	done;																														\
	AVERAGE=$$((TOTAL_MOVES / $(RUN)));																							\
	SUCCESS_PERCENTAGE=$$((SUCCESS_COUNT * 100 / $(RUN)));																		\
	echo "$(RESET_LINE)$(BOLD_OPACITY)[ PUSH_SWAP ]$(DEF_STYLE)	Resultats pour $(RUN) tests avec $(ELM) éléments:";				\
	echo "$(BOLD_OPACITY)[ PUSH_SWAP ]$(DEF_STYLE)	Coups en moyenne:		$(MAGENTA) $$AVERAGE $(DEF_COLOR)";						\
	echo "$(BOLD_OPACITY)[ PUSH_SWAP ]$(DEF_STYLE)	Coups minimum:			$(MAGENTA) $$MIN_MOVES $(DEF_COLOR)";					\
	echo "$(BOLD_OPACITY)[ PUSH_SWAP ]$(DEF_STYLE)	Coups maximum:			$(MAGENTA) $$MAX_MOVES $(DEF_COLOR)";					\
	echo "$(BOLD_OPACITY)[ PUSH_SWAP ]$(DEF_STYLE)	Tests avec moins de $(MAX) coups:	$(MAGENTA) $$SUCCESS_COUNT $(DEF_COLOR)";	\
	echo "$(BOLD_OPACITY)[ PUSH_SWAP ]$(DEF_STYLE)	Pourcentage de réussite:	$(MAGENTA) $$SUCCESS_PERCENTAGE% $(DEF_COLOR)"

re				:	fclean all

.PHONY			:	all bonus clean fclean re runtest