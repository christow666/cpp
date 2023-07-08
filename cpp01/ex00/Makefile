NAME = BraiiiiiiinnnzzzZ

CFLAGS = -std=c++98 -Wall -Wextra -Werror

CC = c++

SRC = main.cpp\
	newZombie.cpp\
	randomChump.cpp
	
OBJ = $(SRC:.cpp=.o)

RM = rm -rf

all : $(NAME) $(SRC)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

run : $(NAME) $(SRC)
	./$(NAME)
	
clean : 
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)