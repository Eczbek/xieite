# [`xieite`](../../README.md)`::`[`meta`](../../docs/meta.md)`::Version`
Defined in header [`<xieite/meta/Version.hpp>`](../../include/xieite/meta/Version.hpp)

<br/>

A class to store and compare versions.

<br/><br/>

## Synopsis

<br/>

```cpp
struct Version final {
	std::size_t major;
	std::size_t minor;
	std::size_t patch;
	std::string label;

	constexpr Version(std::size_t = 0, std::size_t = 0, std::size_t = 0, std::string_view = "");

	constexpr std::strong_ordering operator<=>(const xieite::meta::Version&) const;

	constexpr std::string string() const;
};
```
### Member objects
- `major` - A `std::size_t`
- `minor` - A `std::size_t`
- `patch` - A `std::size_t`
- `label` - A `std::string`
### Member functions
- [`Version`](../../docs/meta/Version/constructor.md)
- [`operator<=>`](../../docs/meta/Version/operatorSpaceship.md)
- [`string`](../../docs/meta/Version/string.md)

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/meta/Version.hpp>

int main() {
	std::cout << xieite::meta::Version(1, 43, 998, "alpha").string() << '\n';
}
```
Output:
```
v1.43.998-alpha
```
