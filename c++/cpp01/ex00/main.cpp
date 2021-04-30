#include "Pony.hpp"

void	ponyOnTheStack()
{
	Pony poni_stack = Pony("Pepito");
}

void	ponyOnTheHeap()
{
	Pony* poni_heap;

	poni_heap = new Pony("Pepita");
	delete poni_heap;
}

int main()
{
	ponyOnTheStack();
	ponyOnTheHeap();
	return (0);
}
