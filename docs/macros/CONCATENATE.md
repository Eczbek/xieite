# XIEITE_CONCATENATE
Defined in header `<xieite/macros/CONCATENATE.hpp>`

<br/>

Concatenates two values literally.

<br/><br/>

## Declarations
```cpp
#define XIEITE_CONCATENATE(expression1, expression2) \
	XIEITE_CONCATENATE_PRIMITIVE(expression1, expression2)
```

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/macros/CONCATENATE.hpp>

int main() {
	std::cout << (XIEITE_CONCATENATE(4, 5) + 1) << '\n';
}
```
Output:
```
46
```
