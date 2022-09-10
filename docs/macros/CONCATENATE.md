# CONCATENATE
Declared in `<gcufl/macros/CONCATENATE.hpp>`
```cpp
#define CONCATENATE(value1, value2) value1##value2
```
Concatenates two values.
## Example
```cpp
#include <gcufl/macros/CONCATENATE.hpp>
#include <iostream>

int main() {
	std::cout << CONCATENATE(4, 'h') << '\n';
}
```
Output:
```
4h
```
