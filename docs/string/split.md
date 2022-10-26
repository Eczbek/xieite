# xieite::string::split
Declared in `<xieite/string/split.hpp>`
```cpp
[[nodiscard]]
std::vector<std::string> split(const std::string& string, const std::string_view delimiter = "") noexcept;

[[nodiscard]]
std::vector<std::string> split(const std::string& string, const char delimiter) noexcept;

[[nodiscard]]
std::vector<std::string> split(const std::string& string, const std::regex& delimiter) noexcept;
```
Splits a string into a vector of strings.
## Example
```cpp
#include <string>
#include <xieite/string/split.hpp>

int main() {
	for (const std::string_view segment : xieite::string::split("Hello, world!", ' '))
		std::cout << segment << '\n';
}
```
Output:
```
Hello,
world!
```
