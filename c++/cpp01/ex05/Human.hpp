#ifndef HUMAN_HPP
# define HUMAN_HPP

# include "Brain.hpp"
# include <iostream>
# include <string>

class Human
{
	public:
		Human();
		~Human();
		Brain &getBrain();
		std::string identifier();
		Brain cerebro;
};

#endif
