# [xieite](../xieite.md)\:\:[strings](../strings.md)\:\:lowercase
Defined in header [<xieite/strings/lowercase.hpp>](../../include/xieite/strings/lowercase.hpp)

&nbsp;

## Description
Converts a string or character to lowercase. Only handles characters `A` to `Z`

&nbsp;

## Synopses

&nbsp;

```cpp
constexpr char lowercase(char character) noexcept;
```
#### Function parameters
- `character` - A `char`
#### Return type
- `char`

&nbsp;

```cpp
constexpr std::string lowercase(std::string string) noexcept;
```
#### Function parameters
- `string` - A `std::string`
#### Return type
- `std::string`

&nbsp;

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
