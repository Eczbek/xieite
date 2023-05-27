# [xieite](../../README.md)::[meta](../meta.md)::Version
Defined in header [<xieite/meta/Version.hpp>](../../include/xieite/meta/Version.hpp)

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

	constexpr std::strong_ordering operator<=>(const xieite::meta::Version&) const;

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
#include <xieite/meta/Version.hpp>

int main() {
	std::cout << xieite::meta::Version(1, 43, 998, "alpha").string() << '\n';
}
```
Output:
```
v1.43.998-alpha
```
