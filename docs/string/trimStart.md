# `xieite::string::trimStart`
Defined in header [`<xieite/string/trimStart.hpp>`](../../include/xieite/string/trimStart.hpp)

<br/>

Trims the start of a string.

<br/><br/>

## Synopses

<br/>

```cpp
[[nodiscard]]
constexpr std::string trimStart(const std::string& string, char character) noexcept;
```
### Parameters
- `string` - A `std::string` constant reference
- `character` - A `char` copy
### Return value
- A `std::string`

<br/>

```cpp
[[nodiscard]]
constexpr std::string trimStart(const std::string& string, std::span<char> characters) noexcept;
```
### Parameters
- `string` - A `std::string` constant reference
- `characters` - A constant reference to a `std::vector` of `char`s
### Return value
- A `std::string`

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/string/trimStart.hpp>

int main() {
	std::cout << xieite::string::trimStart("bababananana", { 'a', 'b' }) << '\n';
}
```
Output:
```
nanana
```
