# gcufl::string::trimEnd
```cpp
std::string trimEnd(const std::string& string, const char character) noexcept;

std::string trimEnd(const std::string& string, std::string_view characters) noexcept;
```
Removes characters from the end of a string.
## Example
```cpp
#include <iostream>
#include <gcufl/string.hpp>

int main() {
	std::cout << gcufl::string::trimEnd("...l...", '.') << '\n';
}
```
Output:
```
...l
```
