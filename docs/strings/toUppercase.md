# [`xieite`](../../README.md)`::`[`strings`](../../docs/strings.md)`::toUppercase`
Defined in header [`<xieite/strings/toUppercase.hpp>`](../../include/xieite/strings/toUppercase.hpp)

<br/>

Converts a string or character to uppercase. Only handles characters `a` to `z`.

<br/><br/>

## Synopses

<br/><br/>

```cpp
constexpr char toUppercase(char character) noexcept;
```
### Parameters
- `character` - A `char` copy
### Return value
- A `char`

<br/><br/>

```cpp
constexpr std::string toUppercase(std::string string) noexcept;
```
### Parameters
- `string` - A `std::string` copy
### Return value
- A `std::string`

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/strings/toUppercase.hpp>

int main() {
	std::cout << xieite::strings::toUppercase("hello, world!\n");
}
```
Output:
```
HELLO, WORLD!
```
