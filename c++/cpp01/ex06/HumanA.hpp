#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <iostream>
# include <string>
# include "Weapon.hpp"

class HumanA
{
	public:
		HumanA(std::string name, Weapon &type);
		~HumanA();
		void attack() const;

	private:
		std::string	_name;
		Weapon&		_type;
};


#endif
