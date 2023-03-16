# XIEITE_QUOTE
Defined in header `<xieite/macros/QUOTE.hpp>`

<br/>

Converts an expression to a string literally.

<br/><br/>

## Declarations
```cpp
#define XIEITE_QUOTE(expression) #expression
```

<br/><br/>

## Example
```cpp
#include <iostream> // std::cout
#include <xieite/macros/QUOTE.hpp>

int main() {
	std::cout << XIEITE_QUOTE(2 + 2) << '\n';
}
```
Output:
```
2 + 2
```
