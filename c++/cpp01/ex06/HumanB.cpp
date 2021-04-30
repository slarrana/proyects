#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name)
{
}
HumanB::~HumanB()
{
}

void	HumanB::setWeapon(Weapon &type)
{
	this->_type = &type;
}

void	HumanB::attack() const
{
	std::cout << this->_name << " attacks with his " << this->_type->getType() << std::endl;
}
