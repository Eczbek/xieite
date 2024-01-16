# [XIEITE](../../macros.md)\_PACKED
Defined in header [<xieite/macros/packed.hpp>](../../../include/xieite/macros/packed.hpp)

&nbsp;

## Description
See header file for definitions.

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/macros/packed.hpp>

struct Foo {
	int a;
	char b;
};

struct XIEITE_PACKED(Bar {
	int a;
	char b;
});

int main() {
	std::cout
		<< sizeof(Foo) << '\n'
		<< sizeof(Bar) << '\n';
}
```
Output:
```
8
5
```
