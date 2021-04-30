#include "Brain.hpp"

Brain::Brain()
{
}

Brain::~Brain()
{
}

std::string Brain::identifier()
{
	std::stringstream ret;

	ret << "0x" << std::uppercase <<  std::hex << (long)this;
	return (ret.str());
}
