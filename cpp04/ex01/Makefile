ORANGE =		\033[38;5;209m
PURPLE=			\033[0;35m
YELLOW =		\033[0;93m
GREEN =			\033[0;92m
WHITE =			\033[0;37m

NAME = Animal

CC = c++
CFLAGS = -Wall -Wextra -Werror -Wshadow -std=c++98 -fsanitize=address

SRC_PATH = ./src/
OBJ_PATH = ./objects/
INC_PATH = ./inc/
SRC = main.cpp \
		Animal.cpp \
		Dog.cpp \
		Cat.cpp \
		WrongAnimal.cpp \
		WrongCat.cpp \
		Brain.cpp \
		
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
		@$(CC) $(CFLAGS) $(INC) -o $(NAME) $(OBJS)
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