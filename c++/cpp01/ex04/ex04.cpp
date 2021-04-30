#include <string>
#include <iostream>

int main()
{
	std::string brain = "HI THIS IS BRAIN";
	std::string *ptr;
	std::string &ref = brain;

	ptr = &brain;

	std::cout << "brain: " << brain << " puntero: " << *ptr << " referencia: " << ref << std::endl;
	return (0);
}
