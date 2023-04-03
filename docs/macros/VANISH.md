# XIEITE_VANISH
Defined in header `<xieite/macros/VANISH.hpp>`

<br/>

Uses magic to remove any line where it is mentioned (see example).

<br/><br/>

## Declarations
```cpp
#define XIEITE_VANISH \
	sizeof(decltype(std))
```

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/macros/VANISH.hpp>

int main() {
	int x = 5;
	
	XIEITE_VANISH, x = 999;

	std::cout << x << '\n';

	std::cout << "Hello, world!\n" << XIEITE_VANISH;
}
```
Output:
```
5
```
