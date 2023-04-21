# [`xieite`](../../README.md)`::`[`string`](../../docs/string.md)`::split`
Defined in header [`<xieite/string/split.hpp>`](../../include/xieite/string/split.hpp)

<br/>

Splits a string into a vector of substrings.

<br/><br/>

## Synopses

<br/>

```cpp
[[nodiscard]]
constexpr std::vector<std::string> split(const std::string& string, std::string_view delimiter = "") noexcept;
```
### Parameters
- `string` - A `std::string` constant reference
- `delimiter` - A `std::string_view` copy
### Return value
- A `std::vector` of `std::string` segments

<br/>

```cpp
[[nodiscard]]
constexpr std::vector<std::string> split(const std::string& string, char delimiter) noexcept;
```
### Parameters
- `string` - A `std::string` constant reference
- `delimiter` - A `char` copy
### Return value
- A `std::vector` of `std::string` segments

<br/><br/>

## Example
```cpp
#include <iostream>
#include <string_view>
#include <xieite/string/split.hpp>

int main() {
	for (std::string_view segment : xieite::string::split("Hello, world!", ' ')) {
		std::cout << segment << '\n';
	}
}
```
Output:
```
Hello,
world!
```
