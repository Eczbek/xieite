# GCUFL_REPEAT
Declared in `<gcufl/macros/REPEAT.hpp>`
```cpp
#define GCUFL_REPEAT(x, y) GCUFL_CONCAT(GCUFL_REPEAT_, y)(x)
```
Repeats an expression literally.
## Example
```cpp
#include <gcufl/macros/REPEAT.hpp>
#include <iostream>

int main() {
	std::cout << (GCUFL_REPEAT(5, 3) + 1) << '\n';
}
```
Output:
```
556
```
