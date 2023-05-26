# [`xieite`](../../README.md)`::`[`strings`](../../docs/strings.md)`::trimFront`
Defined in header [`<xieite/strings/trimFront.hpp>`](../../include/xieite/strings/trimFront.hpp)

<br/>

Trims the front of a string.

<br/><br/>

## Synopses

<br/><br/>

```cpp
[[nodiscard]]
constexpr std::string trimFront(const std::string& string, char character) noexcept;
```
### Parameters
- `string` - A `std::string` constant reference
- `character` - A `char` copy
### Return value
- A `std::string`

<br/><br/>

```cpp
[[nodiscard]]
constexpr std::string trimFront(const std::string& string, const xieite::concepts::RangeOf<char> auto& characters) noexcept;
```
### Parameters
- `string` - A `std::string` constant reference
- `characters` - An `auto` constant reference, satisfying `xieite::concepts::RangeOf` of `char`
### Return value
- A `std::string`

<br/><br/>

## Example
```cpp
#include <iostream>
#include <vector>
#include <xieite/strings/trimFront.hpp>

int main() {
	std::vector<char> characters {
		'a',
		'b'
	};

	std::cout << xieite::strings::trimFront("bababananana", characters) << '\n';
}
```
Output:
```
nanana
```