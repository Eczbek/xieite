# [xieite](../xieite.md)\:\:[strings](../strings.md)\:\:repeat
Defined in header [<xieite/strings/repeat.hpp>](../../include/xieite/strings/repeat.hpp)

&nbsp;

## Description
Repeats a string

&nbsp;

## Synopsis
```cpp
[[nodiscard]]
constexpr std::string repeat(std::string_view string, std::size_t count) noexcept;
```
#### Function parameters
- `string` - A `std::string_view`, the value to repeat
- `count` - A `std::size_t`, how many times to repeat string
#### Return type
- `std::string`

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/strings/repeat.hpp>

int main() {
    std::cout << xieite::strings::repeat("Hello, world!\n", 3);
}
```
Output:
```
Hello, world!
Hello, world!
Hello, world!
```
