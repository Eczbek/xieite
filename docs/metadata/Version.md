# [xieite](../../README.md)::[metadata](../metadata.md)::Version
Defined in header [<xieite/metadata/Version.hpp>](../../include/xieite/metadata/Version.hpp)

<br/>

A class to store and compare versions

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

	constexpr std::strong_ordering operator<=>(const xieite::metdata::Version&) const;

	constexpr std::string string() const;
};
```
### Public members
<pre><code>Version/
|- major
|- minor
|- patch
|- label
|- <a href="./Version/consructor.md">Version</a>
|- <a href="./Version/operatorSpaceship.md">operator<=></a>
`- <a href="./Version/string.md">string</a>
</code></pre>

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/metadata/Version.hpp>

int main() {
	std::cout << xieite::metadata::Version(1, 43, 998, "alpha").string() << '\n';
}
```
Output:
```
v1.43.998-alpha
```
