NAME=test
CC=c++
CFLAGS=-std=c++98 -Wall -Wextra -Werror
SRCS=\
	Animal.cpp\
	Cat.cpp\
	Dog.cpp\
	main.cpp\
	WrongAnimal.cpp\
	WrongCat.cpp

OBJS=$(SRCS:.cpp=.o)
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@
all: $(NAME)
clean:
	rm -f $(OBJS)
fclean: clean 
	rm -f $(NAME)
re: fclean  all
