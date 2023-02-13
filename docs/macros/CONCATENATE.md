# XIEITE_CONCATENATE
Declared in `<xieite/macros/CONCATENATE.hpp>`

<br/>

Combines two values.

<br/><br/>

## Definition
```cpp
#define XIEITE_CONCATENATE(x, y) XIEITE_CONCATENATE_PRIMITIVE(x, y)
```

<br/><br/>

## Example
```cpp
#include <iostream> // std::cout
#include <xieite/macros/CONCATENATE.hpp>

int main() {
	std::cout << (XIEITE_CONCATENATE(4, 5) + 1) << '\n';
}
```
Output:
```
46
```
