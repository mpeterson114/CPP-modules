ORANGE =		\033[38;5;209m
PURPLE=			\033[0;35m
YELLOW =		\033[0;93m
GREEN =			\033[0;92m
WHITE =			\033[0;37m

NAME = replace

SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
REMOVE = rm -f

all: $(NAME)

$(NAME) : $(OBJS)
		@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)	
		@echo "\n$(GREEN)Objects and executables created successfully ✅\n"

%.o: %.cpp
		@echo "$(YELLOW) Compiling	$(WHITE)$<"
		@$(CC) $(CFLAGS) -c $< -o $@

clean:
		@$(REMOVE) $(OBJS)
		@echo "\n$(PURPLE) Objects cleaned successfully ✅\n"

fclean:
		@$(REMOVE) $(OBJS)
		@$(REMOVE) $(NAME)
		@echo "\n$(ORANGE) Objects and executables deleted successfully ✅\n"
	
re:		fclean all

.PHONY:	all clean fclean re