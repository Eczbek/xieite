# GCUFL_CONCAT
Declared in `<gcufl/macros/CONCAT.hpp>`
```cpp
#define GCUFL_CONCAT(x, y) GCUFL_CONCAT_PRIMITIVE(x, y)

#define GCUFL_CONCAT_PRIMITIVE(x, y) x ## y
```
Concatenates two values.
## Example
```cpp
#include <gcufl/macros/CONCAT.hpp>
#include <iostream>

int main() {
	std::cout << GCUFL_CONCAT(4, 'h') << '\n';
}
```
Output:
```
4h
```
