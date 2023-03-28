# xieite::string::split
Defined in header `<xieite/string/split.hpp>`

<br/>

Splits a string into a vector of substrings.

<br/><br/>

## Declarations
```cpp
[[nodiscard]]
constexpr std::vector<std::string> split(const std::string& string, std::string_view delimiter = "") noexcept;
```
```cpp
[[nodiscard]]
constexpr std::vector<std::string> split(const std::string& string, char delimiter) noexcept;
```

<br/><br/>

## Example
```cpp
#include <iostream>
#include <string_view>
#include <xieite/string/split.hpp>

int main() {
	for (std::string_view segment : xieite::string::split("Hello, world!", ' '))
		std::cout << segment << '\n';
}
```
Output:
```
Hello,
world!
```
