# [xieite](../xieite.md)::[strings](../strings.md)::toLower
Defined in header [<xieite/strings/toLower.hpp>](../../include/xieite/strings/toLower.hpp)

<br/>

Converts a string or character to lowercase. Only handles characters `A` to `Z`

<br/><br/>

## Synopses

<br/><br/>

```cpp
constexpr char toLower(char character) noexcept;
```
### Parameters
- `character` - A `char`
### Return value
- A `char`

<br/><br/>

```cpp
constexpr std::string toLower(std::string string) noexcept;
```
### Parameters
- `string` - A `std::string`
### Return value
- A `std::string`

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/strings/toLower.hpp>

int main() {
	std::cout << xieite::strings::toLower("HELLO, WORLD!\n");
}
```
Output:
```
hello, world!
```
