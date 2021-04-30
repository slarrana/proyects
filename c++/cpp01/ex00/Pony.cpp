#include "Pony.hpp"
#include <iostream>

Pony::Pony(std::string nombre) : _nombre(nombre)
{
	std::cout << "Ha nacido un poni! Se llama " << this->_nombre << std::endl;
}

Pony::~Pony(void)
{
	std::cout << this->_nombre << " ha muerto =(" << std::endl;
}
