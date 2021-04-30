#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
	public:
		Zombie();
		~Zombie();
		void	announce() const;
		void	name_zombie(std::string name, std::string type);
	private:
		std::string _nombre;
		std::string _type;
};

#endif
