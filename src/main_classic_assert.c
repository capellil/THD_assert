#include "assert.h"

void test_component_A()
{
	assert(1 == 1);
	assert(2 == 1);
	assert(3 == 1);
}

void test_component_B()
{
	assert(1 == 1);
	assert(2 == 1);
	assert(3 == 3);
}

int main()
{
	test_component_A();
	test_component_B();
}
