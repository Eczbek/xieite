# gcufl::string::trunc
```cpp
std::string trunc(const std::string& string, const std::size_t length, const std::string& suffix = "...") noexcept;
```
Truncates a string to set length.
## Example
```cpp
#include <iostream>
#include <gcufl/string.hpp>

int main() {
	std::cout << gcufl::string::trunc("Hello, world!", 8) << '\n';
}
```
Output:
```
Hello...
```
