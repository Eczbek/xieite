# gcufl::string::trimStart
Declared in `<gcufl/string/trimStart.hpp>`
```cpp
std::string trimStart(const std::string& string, const std::string_view characters) noexcept;

std::string trimStart(const std::string& string, const char character) noexcept;
```
Trims the start of a string.
<br/>
The second variation accepts multiple characters in a `std::string_view`, of which all characters are used to trim a string.
## Example
```cpp
#include <gcufl/string/trimStart.hpp>
#include <iostream>

int main() {
	std::cout << gcufl::string::trimStart("bababananana", "ab") << '\n';
}
```
Output:
```
nanana
```
