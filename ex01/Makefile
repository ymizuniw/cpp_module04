#common sorces
COMMON_SRCS = Animal.cpp \
Cat.cpp \
Dog.cpp \
WrongAnimal.cpp \
WrongCat.cpp \
Brain.cpp \
print_utils.cpp

#compiler
CXX = c++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror -pedantic-errors
CPP = -I.

DEBUG = 0
ifeq ($(DEBUG),1)
	DFLAGS=-g -DDEBUG=1
endif

#pattern rules
%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(DFLAGS) -c $< -o $@

#name0
NAME_0 = test00
SRCS_0 = $(COMMON_SRCS) main0.cpp
OBJS_0=$(SRCS_0:%.cpp=%.o)
#name1
NAME_1 = test01
SRCS_1 = $(COMMON_SRCS) main1.cpp
OBJS_1=$(SRCS_1:%.cpp=%.o)

TESTS = $(NAME_0) $(NAME_1)
OBJS = $(OBJS_0) $(OBJS_1)
#build all tests
all: $(TESTS)

$(NAME_0): $(OBJS_0)
	$(CXX) $(CXXFLAGS) $(CPP) -o $@ $(OBJS_0)
$(NAME_1): $(OBJS_1)
	$(CXX) $(CXXFLAGS) $(CPP) -o $@ $(OBJS_1)

#orthodox rules
clean:
	$(RM) -f $(OBJS)
fclean: 
	$(MAKE) clean
	$(RM) -f $(TESTS)
re:
	$(MAKE) fclean
	$(MAKE) all
.PHONY: all clean fclean re