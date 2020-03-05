#include "THD_assert.h"

void test_component_A()
{
	THD_assert(1 == 1);
	THD_assert(2 == 1);
	THD_assert(3 == 1);
}

void test_component_B()
{
	THD_assert(1 == 1);
	THD_assert(2 == 1);
}

int main()
{
	test_component_A();
	test_component_B();
}
