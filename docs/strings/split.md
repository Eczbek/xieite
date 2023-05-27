# [xieite](../../README.md)::[strings](../strings.md)::split
Defined in header [<xieite/strings/split.hpp>](../../include/xieite/strings/split.hpp)

<br/>

Splits a string into a vector of substrings

<br/><br/>

## Synopses

<br/><br/>

```cpp
[[nodiscard]]
constexpr std::vector<std::string> split(const std::string& string, std::string_view delimiter = "") noexcept;
```
### Parameters
- `string` - A `std::string` constant reference
- `delimiter` - A `std::string_view` copy, set to `""` by default
### Return value
- A `std::vector` of `std::string`s

<br/><br/>

```cpp
[[nodiscard]]
constexpr std::vector<std::string> split(const std::string& string, char delimiter) noexcept;
```
### Parameters
- `string` - A `std::string` constant reference
- `delimiter` - A `char` copy
### Return value
- A `std::vector` of `std::string`s

<br/><br/>

## Example
```cpp
#include <iostream>
#include <string_view>
#include <xieite/strings/split.hpp>

int main() {
	for (std::string_view segment : xieite::strings::split("Hello, world!", ' ')) {
		std::cout << segment << '\n';
	}
}
```
Output:
```
Hello,
world!
```
