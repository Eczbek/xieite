# [xieite](../../xieite.md)\:\:[strings](../../strings.md)\:\:IntegerComponents \{\}
Defined in header [<xieite/strings/integer_components.hpp>](../../../include/xieite/strings/integer_components.hpp)

&nbsp;

## Description
A namespace of collections of characters.

&nbsp;

## Synopsis
#### 1)
```cpp
struct IntegerComponents {
    const std::string digits = std::string(xieite::strings::characters::alphanumeric);
    const char negative = '-';
    const char positive = '+';
    const char point = '.';
    const char exponent = 'e';
};
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/strings/integer_components.hpp"

int main() {
    std::println("{}", xieite::strings::IntegerComponents().digits);
}
```
Output:
```
0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz
```
