# [`xieite`](../../README.md)`::`[`strings`](../../docs/strings.md)`::toLowercase`
Defined in header [`<xieite/strings/toLowercase.hpp>`](../../include/xieite/strings/toLowercase.hpp)

<br/>

Converts a string or character to lowercase. Only handles characters `A` to `Z`.

<br/><br/>

## Synopses

<br/><br/>

```cpp
constexpr char toLowercase(char character) noexcept;
```
### Parameters
- `character` - A `char` copy
### Return value
- A `char`

<br/><br/>

```cpp
constexpr std::string toLowercase(std::string string) noexcept;
```
### Parameters
- `string` - A `std::string` copy
### Return value
- A `std::string`

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/strings/toLowercase.hpp>

int main() {
	std::cout << xieite::strings::toLowercase("HELLO, WORLD!\n");
}
```
Output:
```
hello, world!
```
