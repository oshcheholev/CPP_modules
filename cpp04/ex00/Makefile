#------------------------------------------------------------------------------#

CPP			= c++
RM			= rm -rf
FLAGS	= -Wall -Wextra -Werror -std=c++98
MAKEFLAGS	= -j$(nproc) --no-print-directory

NAME		= animals

SRCS		= main.cpp \
			Animal.cpp \
			Cat.cpp \
			Dog.cpp \
			WrongAnimal.cpp \
			WrongCat.cpp \
		

OBJSDIR		= obj
OBJS		= $(addprefix $(OBJSDIR)/, $(SRCS:.cpp=.o))
DEPS		= $(addprefix $(OBJSDIR)/, $(SRCS:.cpp=.d))

#------------------------------------------------------------------------------#

all		: $(NAME)

$(NAME)	: ${OBJS}
		$(CPP) ${FLAGS} -o $@ $^


${OBJSDIR}/%.o	: %.cpp
		@mkdir -p $(dir $@)
		${CPP} ${FLAGS} -c $< -o $@

clean	:
		$(RM) $(OBJSDIR)

fclean	:
		$(RM) $(OBJSDIR) $(NAME)

re		:
		$(RM) $(OBJSDIR) $(NAME)
		$(MAKE) all

-include $(DEPS)

.PHONY	: all clean fclean re