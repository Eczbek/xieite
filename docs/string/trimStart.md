# gcufl::string::trimStart
```cpp
std::string trimStart(const std::string& string, const char character) noexcept;

std::string trimStart(const std::string& string, std::string_view characters) noexcept;
```
Removes characters from the beginning of a string.
## Example
```cpp
#include <gcufl/string.hpp>
#include <iostream>

int main() {
	std::cout << gcufl::string::trimStart("...l...", '.') << '\n';
}
```
Output:
```
l...
```
