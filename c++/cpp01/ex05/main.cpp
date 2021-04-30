#include "Brain.hpp"
#include "Human.hpp"

int main()
{
	Human bob;

	std::cout << bob.identifier() << std::endl;
	std::cout << bob.getBrain().identifier() << std::endl;
}
