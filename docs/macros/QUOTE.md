# QUOTE
```cpp
#define QUOTE(expression)
```
Creates a stringified expression.
## Example
```cpp
#include <iostream>
#include <gcufl/macros.hpp>

int main() {
	std::cout << QUOTE(2 + 2) << '\n';
}
```
Output:
```
2 + 2
```
