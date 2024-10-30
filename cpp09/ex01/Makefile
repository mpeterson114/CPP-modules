ORANGE =		\033[38;5;209m
PURPLE=			\033[0;35m
YELLOW =		\033[0;93m
GREEN =			\033[0;92m
WHITE =			\033[0;37m

NAME = RPN

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -fsanitize=address #-pedantic

SRC_PATH = ./src/
OBJ_PATH = ./objects/
INC_PATH = ./inc/
SRC = main.cpp \
		RPN.cpp \

SRCS = $(addprefix $(SRC_PATH), $(SRC))
OBJ = $(SRC:.cpp=.o)
OBJS = $(addprefix $(OBJ_PATH), $(OBJ))
INC = -I $(INC_PATH)
REMOVE = rm -rf

all: $(OBJ_PATH) $(NAME)

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)

$(OBJ_PATH)%.o: $(SRC_PATH)%.cpp
		@echo "$(YELLOW) Compiling	$(WHITE)$<"
		@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(NAME) : $(OBJS)
		@$(CC) $(CFLAGS) $(OBJS) -o $@ $(INC)
		@echo "\n$(GREEN)Objects and executables created successfully ✅\n"

clean:
		@$(REMOVE) $(OBJ_PATH)
		@echo "\n$(PURPLE) Objects cleaned successfully✅\n"

fclean: 
		@$(REMOVE) $(OBJ_PATH)
		@$(REMOVE) $(NAME)
		@echo "\n$(ORANGE) Objects and executables deleted successfully ✅\n"
	
re:		fclean all

.PHONY:	all clean fclean re