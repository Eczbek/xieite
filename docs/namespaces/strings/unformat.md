# [xieite](../../xieite.md)\:\:[strings](../../strings.md)\:\:unformat
Defined in header [<xieite/strings/unformat.hpp>](../../../include/xieite/strings/unformat.hpp)

&nbsp;

## Description
Unformats a string.

&nbsp;

## Synopses
#### 1)
```cpp
template<typename... Types>
requires((... && (xieite::concepts::Arithmetic<Types> || std::constructible_from<Types, std::string_view>)))
constexpr void unformat(std::string_view input, std::string_view format, Types&... results);
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <string>
#include <xieite/strings/unformat.hpp>

int main() {
    std::string x;
    int y;
    double z;

    xieite::strings::unformat("Hello, world! 20 + 3.14159", "Hello, {1}! {0} + {2}", y, x, z);

    std::cout
        << x << '\n'
        << y << '\n'
        << z << '\n';
}
```
Output:
```
world
20
3.14159
```
