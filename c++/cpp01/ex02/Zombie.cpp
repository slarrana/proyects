#include "Zombie.hpp"

void	Zombie::advert() const
{
	std::cout << "<" << this->_nombre << " " << this->_type << "> Braiiiiiiiiinnnssss ..." << std::endl;
}
Zombie::Zombie(std::string nombre, std::string type) : _nombre(nombre), _type(type)
{
	std::cout << this->_nombre << " ha resurgido como un zombie!!" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << _nombre << " ha muerto del todo!" << std::endl;
}
