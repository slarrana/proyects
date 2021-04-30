#include "Human.hpp"

Human::Human()
{
}

Human::~Human()
{
}

Brain	&Human::getBrain()
{
	return (this->cerebro);
}

std::string Human::identifier()
{
	return (this->cerebro.identifier());
}
