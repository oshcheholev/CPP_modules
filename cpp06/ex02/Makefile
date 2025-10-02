#------------------------------------------------------------------------------#

CPP			= c++
RM			= rm -rf
FLAGS	= -Wall -Wextra -Werror -g -std=c++98

NAME		= identify

SRCS		= main.cpp \
			  A.cpp \
			  B.cpp \
			  C.cpp \
			  Base.cpp
		
		

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