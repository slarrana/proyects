#include "Zombie.hpp"

void	Zombie::announce() const
{
	std::cout << "<" << this->_nombre << " " << this->_type << "> Braiiiiiiiiinnnssss ..." << std::endl;
}

void	Zombie::name_zombie(std::string name, std::string type)
{
	this->_nombre = name;
	this->_type = type;

	std::cout << this->_nombre << " " << this->_type << " ha resurgido como un zombie!" << std::endl;
}
Zombie::Zombie()
{
}

Zombie::~Zombie()
{
	std::cout << _nombre << " ha muerto del todo!" << std::endl;
}
