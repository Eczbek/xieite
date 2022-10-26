# xieite::string::trimEnd
Declared in `<xieite/string/trimEnd.hpp>`
```cpp
[[nodiscard]]
std::string trimEnd(const std::string& string, const std::string_view characters) noexcept;

[[nodiscard]]
std::string trimEnd(const std::string& string, const char character) noexcept;
```
Trims the end of a string. The second variation accepts multiple characters in a `std::string_view`, of which all characters are used to trim a string.
## Example
```cpp
#include <iostream>
#include <xieite/string/trimEnd.hpp>

int main() {
	std::cout << xieite::string::trimEnd("bababananana", "an") << '\n';
}
```
Output:
```
babab
```
