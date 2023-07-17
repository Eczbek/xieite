# [xieite](../xieite.md)::[strings](../strings.md)::toUpper
Defined in header [<xieite/strings/toUpper.hpp>](../../include/xieite/strings/toUpper.hpp)

<br/>

Converts a string or character to uppercase. Only handles characters `a` to `z`

<br/><br/>

## Synopses

<br/><br/>

```cpp
constexpr char toUpper(char character) noexcept;
```
### Parameters
- `character` - A `char` copy
### Return value
- A `char`

<br/><br/>

```cpp
constexpr std::string toUpper(std::string string) noexcept;
```
### Parameters
- `string` - A `std::string` copy
### Return value
- A `std::string`

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/strings/toUpper.hpp>

int main() {
	std::cout << xieite::strings::toUpper("hello, world!\n");
}
```
Output:
```
HELLO, WORLD!
```
