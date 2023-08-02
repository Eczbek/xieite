# [xieite](../xieite.md)::[strings](../strings.md)::lowercase
Defined in header [<xieite/strings/lowercase.hpp>](../../include/xieite/strings/lowercase.hpp)

<br/>

Converts a string or character to lowercase. Only handles characters `A` to `Z`

<br/><br/>

## Synopses

<br/><br/>

```cpp
constexpr char lowercase(char character) noexcept;
```
### Parameters
- `character` - A `char`
### Return value
- A `char`

<br/><br/>

```cpp
constexpr std::string lowercase(std::string string) noexcept;
```
### Parameters
- `string` - A `std::string`
### Return value
- A `std::string`

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/strings/lowercase.hpp>

int main() {
	std::cout << xieite::strings::lowercase("HELLO, WORLD!\n");
}
```
Output:
```
hello, world!
```
