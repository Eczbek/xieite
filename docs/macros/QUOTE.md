# QUOTE
Defined in `<gcufl/macros/QUOTE.hpp>`
<br/><br/>
```cpp
#define QUOTE(expression) #expression
```
Converts an expression to a string literally.
## Example
```cpp
#include <gcufl/macros/QUOTE.hpp>
#include <iostream>

int main() {
	std::cout << QUOTE(2 + 2) << '\n';
}
```
Output:
```
2 + 2
```
