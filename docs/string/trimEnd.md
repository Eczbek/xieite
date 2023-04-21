# `xieite::string::trimEnd`
Defined in header [`<xieite/string/trimEnd.hpp>`](../../include/xieite/string/trimEnd.hpp)

<br/>

Trims the end of a string.

<br/><br/>

## Synopses

<br/>

```cpp
[[nodiscard]]
constexpr std::string trimEnd(const std::string& string, char character) noexcept;
```
### Parameters
- `string` - A `std::string` constant reference
- `character` - A `char` copy
### Return value
- A `std::string`

<br/>

```cpp
[[nodiscard]]
constexpr std::string trimEnd(const std::string& string, std::span<char> characters) noexcept;
```
### Parameters
- `string` - A `std::string` constant reference
- `characters` - A `std::span` of `char`s
### Return value
- A `std::string`

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/string/trimEnd.hpp>

int main() {
	std::cout << xieite::string::trimEnd("bababananana", { 'a', 'n' }) << '\n';
}
```
Output:
```
babab
```
