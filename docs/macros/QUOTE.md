# GCUFL_QUOTE
Declared in `<gcufl/macros/QUOTE.hpp>`
```cpp
#define GCUFL_QUOTE(expression) \
	#expression
```
Converts an expression to a string literally.
## Example
```cpp
#include <gcufl/macros/QUOTE.hpp>
#include <iostream>

int main() {
	std::cout << GCUFL_QUOTE(2 + 2) << '\n';
}
```
Output:
```
2 + 2
```
