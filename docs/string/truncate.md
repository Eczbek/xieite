# `xieite::string::truncate`
Defined in header [`<xieite/string/truncate.hpp>`](https://github.com/Eczbek/xieite/tree/main/include/xieite/string/truncate.hpp)

<br/>

Shortens the end of a string, replacing it with a suffix.

<br/><br/>

## Synopsis

<br/>

```cpp
[[nodiscard]]
constexpr std::string truncate(const std::string& string, std::size_t length, const std::string& suffix = "") noexcept;
```
### Parameters
- `string` - A `std::string` constant reference
- `length` - A `std::size_t` copy, the desired string length
- `suffix` - A `std::string` cosntant reference, set to `""` by default
### Return value
- A `std::string`

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/string/truncate.hpp>

int main() {
	std::cout << xieite::string::truncate("Hello, world!", 8, "...") << '\n';
}
```
Output:
```
Hello...
```
