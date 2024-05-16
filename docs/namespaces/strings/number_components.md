# [xieite](../../xieite.md)\:\:[strings](../../strings.md)\:\:NumberComponents \{\}
Defined in header [<xieite/strings/number_components.hpp>](../../../include/xieite/strings/number_components.hpp)

&nbsp;

## Description
A namespace of collections of integer-related characters.

&nbsp;

## Synopsis
#### 1)
```cpp
struct NumberComponents {
    std::string_view digits = xieite::strings::characters::alphanumeric;
    std::string_view negatives = "-";
    std::string_view positives = "+";
    std::string_view points = ".";
    std::string_view exponents = "Ee";
    std::size_t precision = 50;
};
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/strings/number_components.hpp"

int main() {
    std::println("{}", xieite::strings::NumberComponents().digits);
}
```
Output:
```
0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz
```
