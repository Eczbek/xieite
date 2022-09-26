# gcufl::string::trimEnd
Declared in `<gcufl/string/trimEnd.hpp>`
```cpp
std::string trimEnd(const std::string& string, const std::string_view characters) noexcept;

std::string trimEnd(const std::string& string, const char character) noexcept;
```
Trims the end of a string.
<br/>
The second variation accepts multiple characters in a `std::string_view`, of which all characters are used to trim a string.
## Example
```cpp
#include <gcufl/string/trimEnd.hpp>
#include <iostream>

int main() {
	std::cout << gcufl::string::trimEnd("bababananana", "an") << '\n';
}
```
Output:
```
babab
```
