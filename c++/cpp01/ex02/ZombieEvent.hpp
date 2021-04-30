#ifndef ZOMBIEEVENT_HPP
# define ZOMBIEEVENT_HPP

#include <iostream>
#include <string>
#include "Zombie.hpp"

class ZombieEvent
{
	public:
		ZombieEvent(std::string type);
		~ZombieEvent();
		Zombie *newZombie(std::string name);
		void	randomChump();
		void	setZombieType(std::string type);
		std::string type;
};

#endif
