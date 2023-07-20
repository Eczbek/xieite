# [xieite](../xieite.md)::[strings](../strings.md)::trimBack
Defined in header [<xieite/strings/trimBack.hpp>](../../include/xieite/strings/trimBack.hpp)

<br/>

Trims the back of a string

<br/><br/>

## Synopses

<br/><br/>

```cpp
[[nodiscard]]
constexpr std::string trimBack(const std::string& string, char character) noexcept;
```
### Parameters
- `string` - A `std::string` constant reference
- `character` - A `char`
### Return value
- A `std::string`

<br/><br/>

```cpp
[[nodiscard]]
constexpr std::string trimBack(const std::string& string, const xieite::concepts::RangeOf<char> auto& characters) noexcept;
```
### Parameters
- `string` - A `std::string` constant reference
- `characters` - A constant reference to a value of any type satisfying `xieite::concepts::RangeOf` of `char`
### Return value
- A `std::string`

<br/><br/>

## Example
```cpp
#include <iostream>
#include <vector>
#include <xieite/strings/trimBack.hpp>

int main() {
	std::vector<char> characters {
		'a',
		'n'
	};

	std::cout << xieite::strings::trimBack("bababananana", characters) << '\n';
}
```
Output:
```
babab
```
