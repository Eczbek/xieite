# gcufl::string::toUpper
Declared in `<gcufl/string/toUpper.hpp>`
```cpp
std::string toUpper(std::string string) noexcept;
```
Converts a string to upper case.
## Example
```cpp
#include <gcufl/string/toUpper.cpp>
#include <iostream>

int main() {
	std::cout << gcufl::string::toUpper("Hello, world!\n");
}
```
Output:
```
HELLO, WORLD!
```
