# [xieite](../../README.md)::[strings](../strings.md)::trim
Defined in header [<xieite/strings/trim.hpp>](../../include/xieite/strings/trim.hpp)

<br/>

Trims both the front and back of a string

<br/><br/>

## Synopses

<br/><br/>

```cpp
[[nodiscard]]
constexpr std::string trim(const std::string& string, char character) noexcept;
```
### Parameters
- `string` - A `std::string` constant reference
- `character` - A `char` copy
### Return value
- A `std::string`

<br/><br/>

```cpp
[[nodiscard]]
constexpr std::string trim(const std::string& string, const xieite::concepts::RangeOf<char> auto& characters) noexcept;
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
#include <xieite/strings/trim.hpp>

int main() {
	std::vector<char> characters {
		'b',
		'a',
		'n'
	};

	std::cout << xieite::strings::trim("bababatananana", characters) << '\n';
}
```
Output:
```
t
```
