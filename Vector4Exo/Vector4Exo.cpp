#include <iostream>
#include "Vector4.h"
int main()
{
	Vector4* a = new Vector4(8,7,5,4);
	Vector4* b = new Vector4(1,1);
	Vector4* c = new Vector4(*a + *b);
	std::cout << c->ToString() << std::endl;
	delete a,b,c;
}
