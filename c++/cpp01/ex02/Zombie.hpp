#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
	public:
		Zombie(std::string nombre, std::string type);
		~Zombie();
		void	advert() const;
	private:
		std::string _nombre;
		std::string _type;
};

#endif
