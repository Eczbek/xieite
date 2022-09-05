# QUOTE
```cpp
#define QUOTE(expression)
```
Creates a stringified expression.
## Example
```cpp
#include <gcufl/macros.hpp>
#include <iostream>

int main() {
	std::cout << QUOTE(2 + 2) << '\n';
}
```
Output:
```
2 + 2
```
