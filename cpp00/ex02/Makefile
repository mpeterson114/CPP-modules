ORANGE =		\033[38;5;209m
PURPLE=			\033[0;35m
YELLOW =		\033[0;93m
GREEN =			\033[0;92m
WHITE =			\033[0;37m

NAME = ListAccounts

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -fsanitize=address

SRC = Account.cpp tests.cpp
OBJ = $(SRC:.cpp=.o)
		
REMOVE = rm -rf

all: $(NAME)

%.o: %.cpp
		@echo "$(YELLOW) Compiling	$(WHITE)$<"
		@$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJ)
		@$(CC) $(CFLAGS) $(OBJ) -o $@
		@echo "\n$(GREEN)Objects and executables created successfully ✅\n"

clean:
		@$(REMOVE) $(OBJ)
		@echo "\n$(PURPLE) Objects cleaned successfully✅\n"

fclean: 
		@$(REMOVE) $(OBJ)
		@$(REMOVE) $(NAME)
		@echo "\n$(ORANGE) Objects and executables deleted successfully ✅\n"
	
re:		fclean all

.PHONY:	all clean fclean re