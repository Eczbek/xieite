# [xieite](../xieite.md)\:\:[strings](../strings.md)\:\:uppercase
Defined in header [<xieite/strings/uppercase.hpp>](../../include/xieite/strings/uppercase.hpp)

&nbsp;

## Description
Converts a string or character to uppercase. Only handles characters `a` to `z`

&nbsp;

## Synopses

&nbsp;

```cpp
constexpr char uppercase(char character) noexcept;
```
#### Function parameters
- `character` - A `char`
#### Return type
- `char`

&nbsp;

```cpp
constexpr std::string uppercase(std::string string) noexcept;
```
#### Function parameters
- `string` - A `std::string`
#### Return type
- `std::string`

&nbsp;

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
