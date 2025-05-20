#include <string>


#ifndef HARL_HPP
# define HARL_HPP

# define DEBUG 0
# define INFO 1
# define WARNING 2
# define ERROR 3
# define LEVELS_STR "DEBUG, INFO, WARNING, ERROR"
# define LEVELS_STR_ARR {"DEBUG", "INFO", "WARNING", "ERROR"}


class Harl
{
	public:
		Harl();
		~Harl();
		void complain(std::string level);
	private:
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);
};

#endif
// HARL_HPP