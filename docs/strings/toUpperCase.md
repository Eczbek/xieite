# [`xieite`](../../README.md)`::`[`strings`](../../docs/strings.md)`::toUpperCase`
Defined in header [`<xieite/strings/toUpperCase.hpp>`](../../include/xieite/strings/toUpperCase.hpp)

<br/>

Converts a string or character to uppercase. Only handles characters `a` to `z`.

<br/><br/>

## Synopses

<br/><br/>

```cpp
constexpr char toUpperCase(char character) noexcept;
```
### Parameters
- `character` - A `char` copy
### Return value
- A `char`

<br/><br/>

```cpp
constexpr std::string toUpperCase(std::string string) noexcept;
```
### Parameters
- `string` - A `std::string` copy
### Return value
- A `std::string`

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/strings/toUpperCase.hpp>

int main() {
	std::cout << xieite::strings::toUpperCase("hello, world!\n");
}
```
Output:
```
HELLO, WORLD!
```
