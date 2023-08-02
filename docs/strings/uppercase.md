# [xieite](../xieite.md)::[strings](../strings.md)::uppercase
Defined in header [<xieite/strings/uppercase.hpp>](../../include/xieite/strings/uppercase.hpp)

<br/>

Converts a string or character to uppercase. Only handles characters `a` to `z`

<br/><br/>

## Synopses

<br/><br/>

```cpp
constexpr char uppercase(char character) noexcept;
```
### Parameters
- `character` - A `char`
### Return value
- A `char`

<br/><br/>

```cpp
constexpr std::string uppercase(std::string string) noexcept;
```
### Parameters
- `string` - A `std::string`
### Return value
- A `std::string`

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/strings/uppercase.hpp>

int main() {
	std::cout << xieite::strings::uppercase("hello, world!\n");
}
```
Output:
```
HELLO, WORLD!
```
