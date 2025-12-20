NAME = test00
CXX = c++
CXXCFLAGS = -std=c++98 -Wall -Wextra -Werror
SRCS = \
	Animal.cpp \
	Cat.cpp \
	Dog.cpp \
	main.cpp \
	WrongAnimal.cpp \
	WrongCat.cpp

OBJS=$(SRCS:.cpp=.o)
$(NAME): $(OBJS)
	$(CXX) $(CXXCFLAGS) -o $@ $(OBJS)
%.o: %.c
	$(CXX) $(CXXCFLAGS) -c $< -o $@
%.o: %.cpp
	$(CXX) $(CXXCFLAGS) -c $< -o $@
all: $(NAME)
clean:
	rm -f $(OBJS)
fclean:
	$(MAKE) clean
	rm -f $(NAME)
re:
	$(MAKE) fclean
	$(MAKE) all
