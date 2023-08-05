# [XIEITE](../macros.md)\_VANISH
Defined in header [<xieite/macros/VANISH.hpp>](../../include/xieite/macros/VANISH.hpp)

<br/>

Uses cursed C++ magic to remove any line where it is mentioned. See header file for definitions

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/macros/VANISH.hpp>

int main() {
	int x = 5;
	
	XIEITE__VANISH, x = 999;

	std::cout << x << '\n';

	std::cout << "Hello, world!\n" << XIEITE__VANISH;
}
```
Output:
```
5
```
