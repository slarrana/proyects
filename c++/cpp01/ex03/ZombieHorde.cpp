#include "ZombieHorde.hpp"

ZombieHorde::ZombieHorde(int n) : _n(n)
{
	int i;

	std::string nombres[10] = {"z1", "z2", "z3", "z4", "z5", "z6", "z7", "z8", "z9", "z10"};
	this->zombis = new Zombie[n];
	i = 0;
	while (i < this->_n)
	{
		zombis[i].name_zombie(nombres[rand() % 9], "ZombieHorde");
		i++;
	}
}

ZombieHorde::~ZombieHorde()
{
	delete [] zombis;
}

void	ZombieHorde::announce()
{
	int i;

	while (i < this->_n)
	{
		this->zombis[i].announce();
		i++;
	}
}
