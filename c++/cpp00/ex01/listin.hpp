#ifndef LISTIN_HPP
# define LISTIN_HPP

#include <iomanip>


class listin
{
	public:
		std::string firstname;
		std::string lastname;
		std::string nickname;
		std::string login;
		std::string postal_address;
		std::string email;
		std::string phone;
		std::string birthday;
		std::string meal;
		std::string underwear_color;
		std::string darkest_secret;
};


std::string	fill_list();
listin		ft_add();
void    info_contact(listin contacto);
void	search(listin *contacto, int j);

#endif
