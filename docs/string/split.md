# xieite::string::split
Declared in `<xieite/string/split.hpp>`

<br/>

Splits a string into a vector of segments.

<br/><br/>

## Declarations
```cpp
[[nodiscard]]
constexpr std::vector<std::string> split(const std::string& string, const std::string_view delimiter = "") noexcept;
```
```cpp
[[nodiscard]]
constexpr std::vector<std::string> split(const std::string& string, const char delimiter) noexcept;
```
```cpp
[[nodiscard]]
std::vector<std::string> split(const std::string& string, const std::regex& delimiter) noexcept;
```

<br/><br/>

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
