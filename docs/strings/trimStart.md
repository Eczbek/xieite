# [`xieite`](../../README.md)`::`[`strings`](../../docs/strings.md)`::trimStart`
Defined in header [`<xieite/strings/trimStart.hpp>`](../../include/xieite/strings/trimStart.hpp)

<br/>

Trims the start of a string.

<br/><br/>

## Synopses

<br/><br/>

```cpp
[[nodiscard]]
constexpr std::string trimStart(const std::string& string, char character) noexcept;
```
### Parameters
- `string` - A `std::string` constant reference
- `character` - A `char` copy
### Return value
- A `std::string`

<br/><br/>

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
#include <vector>
#include <xieite/strings/trimStart.hpp>

int main() {
	std::vector<char> characters {
		'a',
		'b'
	};

	std::cout << xieite::strings::trimStart("bababananana", characters) << '\n';
}
```
Output:
```
nanana
```
