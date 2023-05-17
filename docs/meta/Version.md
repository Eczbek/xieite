# [`xieite`](../../README.md)`::`[`meta`](../../docs/meta.md)`::Version`
Defined in header [`<xieite/meta/Version.hpp>`](../../include/xieite/meta/Version.hpp)

<br/>

A class to store and compare versions.

<br/><br/>

## Synopsis

<br/>

### Member objects
```cpp
std::size_t major;
```
```cpp
std::size_t minor;
```
```cpp
std::size_t patch;
```
```cpp
std::string label;
```

<br/>

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
