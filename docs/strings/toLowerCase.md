# [xieite](../../README.md)::[strings](../strings.md)::toLowerCase
Defined in header [<xieite/strings/toLowerCase.hpp>](../../include/xieite/strings/toLowerCase.hpp)

<br/>

Converts a string or character to lowercase. Only handles characters `A` to `Z`

<br/><br/>

## Synopses

<br/><br/>

```cpp
constexpr char toLowerCase(char character) noexcept;
```
### Parameters
- `character` - A `char` copy
### Return value
- A `char`

<br/><br/>

```cpp
constexpr std::string toLowerCase(std::string string) noexcept;
```
### Parameters
- `string` - A `std::string` copy
### Return value
- A `std::string`

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/strings/toLowerCase.hpp>

int main() {
	std::cout << xieite::strings::toLowerCase("HELLO, WORLD!\n");
}
```
Output:
```
hello, world!
```
