NAME = push_swap

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

FILE = main.c \
		lst_utils.c \
		rotate.c \
		swap_push.c \
		reverse_rotate.c \
		hundred.c \
		utils.c \
		under_hundred.c \

PRINTF = ft_printf/ft_printf.a
RM = rm -f
CC = cc
CFLAGS	= -Wall -Werror -Wextra -ggdb
AR	= ar rc
OBJDIR = obj

SRCS = ${FILE}
OBJS = $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))

all:	${NAME}
	@echo "${GREEN}Compilation OK !${RESET}"

${PRINTF}:	
	@echo "${GREEN}Compilation FT_PRINTF...${RESET}"
	@make -s -C ft_printf all

${NAME}:	${OBJS} ${PRINTF}
	@echo "${GREEN}Compilation PUSH_SWAP...${RESET}"
	@${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${PRINTF}

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: %.c | $(OBJDIR)
	@cc $(CFLAGS) -c $< -o $@

clean:
	@echo "${RED}Cleaning...${RESET}"
	@${RM} -rf ${OBJDIR}

fclean: clean
	@echo "$(RED)Cleaning all...$(RESET)"
	@rm -f $(NAME)
	@make -s -C ft_printf fclean

re: fclean all
