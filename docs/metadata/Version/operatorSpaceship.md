# [xieite](../../xieite.md)::[metadata](../../metadata.md)::[Version](../Version.md)::operator<=>
Defined in header [<xieite/metadata/Version.hpp>](../../../include/xieite/metadata/Version.hpp)

<br/>

Compares two `xieite::metadata::Version`s, ingoring the label member object

<br/><br/>

## Synopsis

<br/>

```cpp
[[nodiscard]]
constexpr std::strong_ordering operator<=>(const xieite::metadata::Version& version) const noexcept;
```
### Parameters
- `version` - A `xieite::metadata::Version` constant reference
### Return value
- A `std::strong_ordering`

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/metadata/Version.hpp>

int main() {
	xieite::metadata::Version version1(1, 0, 0, "bbbbb");

	xieite::metadata::Version version2(1, 0, 1, "aaaaa");

	std::cout
		<< std::boolalpha
		<< (version1 < version2) << '\n';
}
```
Output:
```
true
```
