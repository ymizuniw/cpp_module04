NAME = test03
SRCS = AMateria.cpp \
Character.cpp \
Cure.cpp \
Ice.cpp \
MateriaSource.cpp \
orthodox_test.cpp
# main.cpp

OBJS=$(SRCS:%.cpp=%.o)

CXX = c++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror -pedantic-errors -g
CPP = -Iincludes/

all: $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(CPP) -c $< -o $@

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

clean:
	$(RM) $(OBJS)
fclean:
	$(MAKE) clean
	$(RM) $(NAME)
re:
	$(MAKE) fclean
	$(MAKE) all
.PHONY: all clean fclean re
