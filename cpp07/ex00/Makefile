#------------------------------------------------------------------------------#

CPP			= c++
RM			= rm -rf
FLAGS	= -Wall -Wextra -Werror -std=c++98 -g

NAME		= whatever

SRCS		= main.cpp \
			utils.cpp \
			whatever.cpp



OBJSDIR		= obj
OBJS		= $(addprefix $(OBJSDIR)/, $(SRCS:.cpp=.o))

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

.PHONY	: all clean fclean re