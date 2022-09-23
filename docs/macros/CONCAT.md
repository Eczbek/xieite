# GCUFL_CONCAT
Declared in `<gcufl/macros/CONCAT.hpp>`
```cpp
#define GCUFL_CONCAT(value1, value2) \
	value1##value2
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
