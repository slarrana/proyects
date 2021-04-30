#include "Zombie.hpp"
#include "ZombieEvent.hpp"

ZombieEvent::ZombieEvent(std::string type)
{
	this->setZombieType(type);
}

ZombieEvent::~ZombieEvent()
{
}

void	ZombieEvent::setZombieType(std::string type)
{
	this->type = type;
}

Zombie*	ZombieEvent::newZombie(std::string name)
{
	Zombie *zombi = new Zombie(name, this->type);
	return (zombi);
}

void	ZombieEvent::randomChump()
{
	std::string nombres[10] = {"z1", "z2", "z3", "z4", "z5", "z6", "z7", "z8", "z9", "z10"};
	Zombie zombi(nombres[rand() % 9], this->type);
	zombi.advert();
}


