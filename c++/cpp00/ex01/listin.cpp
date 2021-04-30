#include "listin.hpp"
#include <iostream>
#include <string>
#include <limits>

std::string	fill_list()
{
	std::string str;

	std::getline(std::cin, str, '\n');
	while(str.empty())
	{
		std::cout << "Error, introduzca de nuevo el campo deseado: ";
		std::getline(std::cin, str);
	}
	return (str);
}

listin ft_add(void)
{
	listin add;
	
	std::cout << "Introduzca el nombre: ";
	add.firstname = fill_list();
	std::cout << "Introduzca los apellidos: ";
	add.lastname = fill_list();
	std::cout << "Introduzca su Nick: ";
	add.nickname = fill_list();
	std::cout << "Introduzca su login: ";
	add.login = fill_list();
	std::cout << "Introduzca su codigo postal: ";
	add.postal_address = fill_list();
	std::cout << "Introduzca su email: ";
	add.email = fill_list();
	std::cout << "Introduza su numero de telefono: ";
	add.phone = fill_list();
	std::cout << "Introduzca su fecha de cumpleaños: ";
	add.birthday = fill_list();
	std::cout << "Introduzca su comida favorita: ";
	add.meal = fill_list();
	std::cout << "Introduzca el color de su ropa interior: ";
	add.underwear_color = fill_list();
	std::cout << "Introduzca su mas oscuro secreto: ";
	add.darkest_secret = fill_list();
	return (add);
}

void    info_contact(listin contacto)
{
    if (contacto.firstname.empty())
        return;
    std::cout << "Nombre: " << contacto.firstname << std::endl;
    std::cout << "Apellidos: " << contacto.lastname << std::endl;
    std::cout << "Nick: " << contacto.nickname << std::endl;
    std::cout << "Login: " << contacto.login << std::endl;
    std::cout << "C.P: " << contacto.postal_address << std::endl;
    std::cout << "Email: " << contacto.email << std::endl;
    std::cout << "Telefono: " << contacto.phone << std::endl;
    std::cout << "Cumpleaños: " << contacto.birthday << std::endl;
    std::cout << "Comida favorita: " << contacto.meal << std::endl;
    std::cout << "Color de ropa interior: " << contacto.underwear_color << std::endl;
    std::cout << "El mas oscuro secreto: " << contacto.darkest_secret << std::endl;
}


void	search(listin *contacto, int j)
{
	std::string str;
	int i;

	i = 0;
	while (i < j)
	{
		if (contacto[i].firstname.empty())
			break ;
		std::cout.width(10);
		std::cout << i << "|";
		str = contacto[i].firstname;
		if (contacto[i].firstname.size() > 10)
			str.replace(9, str.npos, ".");
		std::cout.width(10);
		std::cout << str << "|";
		str = contacto[i].lastname;
		if (contacto[i].lastname.size() > 10)
			str.replace(9, str.npos, ".");
		std::cout.width(10);
		std::cout << str << "|";
		str = contacto[i].nickname;
		if (contacto[i].nickname.size() > 10)
			str.replace(9, str.npos, ".");
		std::cout.width(10);
		std::cout << str <<  std::endl;
		i++;
	}
}

int main()
{
	listin contacto[8];
    std::string comando;
	int i;
	int j;
	int flag;

	i = 0;
	flag = 0;
	while (flag == 0)
	{
		std::cout << "Introduzca un comando: ADD | SEARCH | EXIT" << std::endl;
		std::cin >> comando;
		std::cin.ignore();
		if (comando.compare("ADD") == 0)
		{
			if (i > 7)
				std::cout << "Listin lleno" << std::endl;
			else
			{
				contacto[i] = ft_add();
				i++;
			}
		}
		else if (comando.compare("SEARCH") == 0)
		{
			search(contacto, i);
			std::cout << "Introduzca el indice del contacto deseado: ";
			std::cin >> j;
			while (std::cin.fail() || j < 0 || j >= i)
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<int>::max(), '\n');
				std::cout << "Error, introduce un indice valido" << std::endl;
				std::cin >> j;
			}
			info_contact(contacto[j]);
		}
		else if (comando.compare("EXIT") == 0)
			flag = 1;
	}
	return (0);

}
