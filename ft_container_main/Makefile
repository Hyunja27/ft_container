NAME = ft_container

SRC_DIR = src
INC_DIR = inc
CC = clang++
C98_FLAG = -std=c++98
GCC_FLAG = -Wall -Wextra -Werror
RM = rm
RMFLAGS = -f

SRC =  $(addprefix $(SRC_DIR)/, \
		main.cpp\
		)

INC =  $(addprefix $(INC_DIR)/, \
		tools.hpp\
		)

GREEN = \033[32m
PURPLE = \033[35m
MINT = \033[36m
RED = \033[31m
BLINK = \033[5m
BOLD = \033[1m
BACKGRAY = \033[100m
NO_COLOR = \e[0m

all : $(NAME)

$(NAME) :
	@echo "${PURPLE}[${RED} Makefile${PURPLE} :starting.. ]"
	@echo "${PURPLE}->making $(NAME).."
	@$(CC) $(C98_FLAG) $(GCC_FLAG) -I $(INC_DIR) $(SRC) -o $(NAME)
	@echo "${PURPLE}->resting.. drinking some coffee..."
	@echo "${MINT}making Done."

clean :
	@echo "${PURPLE}[${RED} cleaning ${PURPLE} : erase objects file.]"
	@($(RM) $(RMFLAGS) $(NAME))
	@echo "${PURPLE}->kill every objects, include libft objects.."
	@echo "${PURPLE}->clearing dead bodys..."
	@echo "${MINT}cleaning Done."

re : clean all

fclean :
	@echo "${PURPLE}[${RED} cleaning ${PURPLE} : erase objects file.]"
	@($(RM) $(RMFLAGS) $(NAME))
	@echo "${PURPLE}->kill every objects, include libft objects.."
	@echo "${PURPLE}->clearing dead bodys..."
	@echo "${MINT}cleaning Done."
