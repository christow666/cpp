NAME = IRT

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98
 
RM = rm -rf

SRC =	main.cpp\
		Base.cpp\


OBJS = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
		$(RM) ${OBJS}

fclean:clean
		$(RM) $(NAME)

re:fclean all

run: all
	./$(NAME) $(filter-out $@,$(MAKECMDGOALS))

leaks: all
	valgrind --leak-check=yes ./$(NAME) $(filter-out $@,$(MAKECMDGOALS))

.PHONY: all clean re fclean run leaks