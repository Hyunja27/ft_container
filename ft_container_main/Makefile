NAME = ft_container

SRC_DIR = src
SRC_DIR_LOG = src/log
INC_DIR = inc
CC = clang++
C98_FLAG = -std=c++98
GCC_FLAG = -Wall -Wextra -Werror
SEG_CHECK = -fsanitize=address -fno-omit-frame-pointer -g
RM = rm
RMFLAGS = -f
STD_NAMESPACE = std
FT_NAMESPACE = ft
CONT = map
TIME = time


SRC =  $(addprefix $(SRC_DIR)/, \
		main.cpp\
		)

INC =  $(addprefix $(INC_DIR)/, \
		container/stack.hpp\
		container/map.hpp\
		container/vector.hpp\
		inc/tools.hpp\
		inc/pair.hpp\
		iterator/vector_iterator.hpp\
		iterator/map_iterator.hpp\
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

mil_test :
	@echo "${PURPLE}[${RED} Makefile${PURPLE} :starting.. ]"
	@bash ./inc/container/containers_test/do.sh

vector :
	@echo "${PURPLE}[${RED} Makefile${PURPLE} :starting.. ]"
	@echo "${PURPLE}->making $(NAME).."
	@$(CC) $(C98_FLAG) $(GCC_FLAG) -I $(INC_DIR) $(SRC_VECTOR) -o $(NAME)
	@echo "${PURPLE}->resting.. drinking some coffee..."
	@echo "${MINT}making Done."

seg_check :
	@echo "${PURPLE}[${RED} Makefile for Segment Check${PURPLE} :starting.. ]"
	@echo "${PURPLE}->making $(NAME).."
	@$(CC) $(C98_FLAG) $(SEG_CHECK) $(GCC_FLAG) -I $(INC_DIR) $(SRC) -o $(NAME)
	@echo "${PURPLE}->resting.. drinking some coffee..."
	@echo "${MINT}making Done."

clean :
	@echo "${PURPLE}[${RED} cleaning ${PURPLE} : erase objects file.]"
	@($(RM) $(RMFLAGS) $(NAME))
	@rm -rf $(SRC_DIR_LOG)
	@echo "${PURPLE}->kill every objects, include libft objects.."
	@echo "${PURPLE}->clearing dead bodys..."
	@echo "${MINT}cleaning Done."

all_type :
	@make own_test CONT=vector
	@make own_test CONT=stack
	@make own_test CONT=map
	@make own_test CONT=set

own_test :
	@mkdir -p $(SRC_DIR_LOG)
	@$(CC) $(CFLAGS) $(SRC_DIR)/$(CONT).cpp -o $(CONT) -I$(INC_DIR) -DTESTED_NAMESPACE=$(FT_NAMESPACE)
	@./$(CONT) > $(SRC_DIR_LOG)/$(FT_NAMESPACE)_$(CONT)
	@$(CC) $(CFLAGS) $(SRC_DIR)/$(CONT).cpp -o $(CONT) -I$(INC_DIR) -DTESTED_NAMESPACE=$(STD_NAMESPACE)
	@./$(CONT) > $(SRC_DIR_LOG)/$(STD_NAMESPACE)_$(CONT)
	@rm $(CONT)

time :
	@make time_unit CONT=vector
	@make time_unit CONT=stack
	@make time_unit CONT=map
	@make time_unit CONT=set

time_unit :
	@$(CC) $(CFLAGS) $(SRC_DIR)/$(CONT).cpp -o $(CONT) -I$(INC_DIR) -DTESTED_NAMESPACE=$(FT_NAMESPACE)
	@printf "\n=====\t$(CONT)\t====="
	@printf "\ntime 'FT'"
	@$(TIME) ./$(CONT) > $(SRC_DIR_LOG)/$(FT_NAMESPACE)_$(CONT)
	@$(CC) $(CFLAGS) $(SRC_DIR)/$(CONT).cpp -o $(CONT) -I$(INC_DIR) -DTESTED_NAMESPACE=$(STD_NAMESPACE)
	@printf "time 'STD'"
	@$(TIME) ./$(CONT) > $(SRC_DIR_LOG)/$(STD_NAMESPACE)_$(CONT)
	@rm $(CONT)

re : clean all

fclean :
	@echo "${PURPLE}[${RED} cleaning ${PURPLE} : erase objects file.]"
	@($(RM) $(RMFLAGS) $(NAME))
	@echo "${PURPLE}->kill every objects, include libft objects.."
	@echo "${PURPLE}->clearing dead bodys..."
	@echo "${MINT}cleaning Done."
