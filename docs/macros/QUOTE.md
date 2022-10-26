# GCUFL_QUOTE
Declared in `<xieite/macros/QUOTE.hpp>`
```cpp
#define GCUFL_QUOTE(x) #x
```
Converts an expression to a string literally.
## Example
```cpp
#include <xieite/macros/QUOTE.hpp>
#include <iostream>

int main() {
	std::cout << GCUFL_QUOTE(2 + 2) << '\n';
}
```
Output:
```
2 + 2
```
