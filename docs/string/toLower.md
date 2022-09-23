# gcufl::string::toLower
Declared in `<gcufl/string/toLower.hpp>`
```cpp
std::string toLower(std::string string) noexcept;
```
Converts a string to lower case.
## Example
```cpp
#include <gcufl/string/toLower.cpp>
#include <iostream>

int main() {
	std::cout << gcufl::string::toLower("STDIN_FILENO\n");
}
```
Output:
```
stdin_fileno
```
