#ifndef PONY_HPP
# define PONY_HPP
#include <string>
#include <iostream>
class Pony
{
	public:
		Pony(std::string nombre);
		~Pony();
	private:
		std::string _nombre;
};

#endif
