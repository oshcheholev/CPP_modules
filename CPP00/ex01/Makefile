#------------------------------------------------------------------------------#
CPP			= c++
RM			= rm -rf
CPPFLAGS	= -Wall -Wextra -Werror -std=c++98
#MAKEFLAGS	= -j$(nproc) --no-print-directory

NAME		= phonebook

SRCS		= PhoneBook.cpp \
			  Contact.cpp \
			  main.cpp

OBJSDIR		= obj
OBJS		= $(addprefix $(OBJSDIR)/, $(SRCS:.cpp=.o))
DEPS		= $(addprefix $(OBJSDIR)/, $(SRCS:.cpp=.d))

#------------------------------------------------------------------------------#

all		: $(NAME)

$(NAME)	: ${OBJS}
		$(CPP) ${CPPFLAGS} ${DFLAGS} -o $@ $^


${OBJSDIR}/%.o	: %.cpp
		@mkdir -p $(dir $@)
		${CPP} ${CPPFLAGS} ${DFLAGS} -c $< -o $@

clean	:
		$(RM) $(OBJSDIR)

fclean	:
		$(RM) $(OBJSDIR) $(NAME)

re		:
		$(RM) $(OBJSDIR) $(NAME)
		$(MAKE) all

-include $(DEPS)

.PHONY	: all clean fclean re