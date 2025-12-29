#------------------------------------------------------------------------------#

CPP			= c++
RM			= rm -rf
FLAGS		= -Wall -Wextra -Werror -std=c++98 -g

NAME		= PmergeMe

SRCS			= main.cpp \
			PmergeMe.cpp \
			PmergeMe_vector.cpp \
			PmergeMe_deque.cpp
OBJSDIR		= obj
OBJS		= $(addprefix $(OBJSDIR)/, $(SRCS:.cpp=.o))

#------------------------------------------------------------------------------#

all		: $(NAME)

$(NAME)	: ${OBJS}
		$(CPP) ${FLAGS} -o $@ $^


${OBJSDIR}/%.o	: %.cpp
		@mkdir -p $(OBJSDIR)
		${CPP} ${FLAGS} -c $< -o $(OBJSDIR)/$*.o

clean	:
		$(RM) $(OBJSDIR)

fclean	:
		$(RM) $(OBJSDIR) $(NAME)

re		:
		$(RM) $(OBJSDIR) $(NAME)
		$(MAKE) all

test: all
	@echo "\n=== Test 1: Small array ==="
	./$(NAME) 3 1 4 11 5 9 2 6
	@echo "\n=== Test 2: With debug mode ==="
	./$(NAME) 5 2 9 1 --debug
	@echo "\n=== Test 3: Reverse order ==="
	./$(NAME) 9 8 7 6 5 4 3 2 1
	@echo "\n=== Test 4: Single element ==="
	./$(NAME) 42
	@echo "\n=== Test 5: Empty input (no args) ==="
	-./$(NAME)
	@echo "\n=== Test 6: Duplicates (should print Error) ==="
	-./$(NAME) 1 2 3 2
	@echo "\n=== Test 7: Non-numeric input (should print Error) ==="
	-./$(NAME) 1 2 a 3
	@echo "\n=== Test 8: Large numbers ==="
	./$(NAME) 2147483647 1000000000 42
	@echo "\n=== Test 9: All-equal elements (should print Error) ==="
	-./$(NAME) 5 5 5 5 5
	@echo "\n=== Test 10: Debug with duplicates ==="
	-./$(NAME) 3 3 1 --debug
	@echo "\n=== Test 11: Random 3000 elements ==="
	./$(NAME) $$(seq 1 3000 | shuf | tr '\n' ' ')
	@echo "\n=== Test 12: Many small-range duplicates (random) ==="
	./$(NAME) $$(shuf -i 0-9 -n 50 -r | tr '\n' ' ')

.PHONY	: all clean fclean re