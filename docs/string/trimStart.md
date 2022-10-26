# xieite::string::trimStart
Declared in `<xieite/string/trimStart.hpp>`
```cpp
[[nodiscard]]
std::string trimStart(const std::string& string, const std::string_view characters) noexcept;

[[nodiscard]]
std::string trimStart(const std::string& string, const char character) noexcept;
```
Trims the start of a string. The second variation accepts multiple characters in a `std::string_view`, of which all characters are used to trim a string.
## Example
```cpp
#include <iostream>
#include <xieite/string/trimStart.hpp>

int main() {
	std::cout << xieite::string::trimStart("bababananana", "ab") << '\n';
}
```
Output:
```
nanana
```
