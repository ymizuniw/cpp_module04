NAME=test
CC=c++
CFLAGS=-std=c++98 -Wall -Wextra -Werror
SRCS=\
	Animal.cpp\
	Animal.hpp\
	Cat.cpp\
	Cat.hpp\
	Dog.cpp\
	Dog.hpp\
	main.c\
	WrongAnimal.cpp\
	WrongAnimal.hpp\
	WrongCat.cpp\
	WrongCat.hpp
OBJS=$(SRCS:.cpp=.o)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@
%.o: %.c
	$(CC) $(CFLAGS) -c $<
all: $(NAME)
clean:
	rm -f $(OBJS)
fclean: clean 
	rm -f $(NAME)
re: fclean  all
