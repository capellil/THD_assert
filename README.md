# THD_assert: A Simple & Lighweight Solution For Pretty Asserts
You just want to write a `main.c` file, test your different functions with a whole bunch of `assert` and get a report about how it went? Cool; in 1 minute you have it, and that includes reading time.
## 1) Installation
Put `#include "THD_assert.h"` in your code.
## 2) How to use
Replace `assert` with `THD_assert` in your code.
## 3) And
Nothing. You are done. Enjoy.
## Example with classic `assert`
### Code
```C
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
```
## Same example, with `THD_assert` instead
### Code
```C
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
  THD_assert(3 == 3);
}

int main()
{
  test_component_A();
  test_component_B();
}
```
