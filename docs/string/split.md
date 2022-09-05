# gcufl::string::split
```cpp
std::vector<std::string> split(const std::string& string, const char delimiter) noexcept;

std::vector<std::string> split(const std::string& string, std::string_view delimiter) noexcept;
```
Splits a string into a vector of strings.
## Example
```cpp
#include <gcufl/string.hpp>
#include <iostream>
#include <string_view>

int main() {
	for (std::string_view segment : gcufl::string::split("Hello, world!", ' '))
		std::cout << segment << '\n';
}
```
Output:
```
Hello,
world!
```
