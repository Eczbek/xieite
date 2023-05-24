# [`xieite`](../../../README.md)`::`[`meta`](../../../docs/meta.md)`::`[`Version`](../../../docs/meta/Version.md)`::operator<=>`
Defined in header [`<xieite/meta/Version.hpp>`](../../../include/xieite/meta/Version.hpp)

<br/>

Compares two `xieite::meta::Version`s, ingoring the `label` member object.

<br/><br/>

## Synopsis

<br/>

```cpp
[[nodiscard]]
constexpr std::strong_ordering operator<=>(const xieite::meta::Version& version) const noexcept;
```
### Parameters
- `version` - A `xieite::meta::Version` constant reference
### Return value
- A `std::strong_ordering`

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/meta/Version.hpp>

int main() {
	xieite::meta::Version version1(1, 0, 0, "bbbbb");

	xieite::meta::Version version2(1, 0, 1, "aaaaa");

	std::cout
		<< std::boolalpha
		<< (version1 < version2)
		<< '\n';
}
```
Output:
```
true
```
