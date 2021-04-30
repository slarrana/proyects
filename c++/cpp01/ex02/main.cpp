#include "Zombie.hpp"
#include "ZombieEvent.hpp"

int main()
{
	ZombieEvent evento("primer evento");
	Zombie *pepe = evento.newZombie("pepe");
	evento.randomChump();
	delete pepe;
	ZombieEvent evento2("segundo evento!!");
	Zombie *pepito = evento2.newZombie("pepito");
	evento2.randomChump();
	evento2.randomChump();
	delete pepito;
}
