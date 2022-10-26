# GCUFL_CONCAT
Declared in `<xieite/macros/CONCAT.hpp>`
```cpp
#define GCUFL_CONCAT(x, y) GCUFL_CONCAT_PRIMITIVE(x, y)

#define GCUFL_CONCAT_PRIMITIVE(x, y) x ## y
```
Concatenates two values.
## Example
```cpp
#include <iostream>
#include <xieite/macros/CONCAT.hpp>

int main() {
	std::cout << GCUFL_CONCAT(4, 'h') << '\n';
}
```
Output:
```
4h
```
