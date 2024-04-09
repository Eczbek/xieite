# [xieite](../../xieite.md)\:\:[strings](../../strings.md)\:\:IntegerComponents \{\}
Defined in header [<xieite/strings/integer_components.hpp>](../../../include/xieite/strings/integer_components.hpp)

&nbsp;

## Description
A namespace of collections of integer-related characters.

&nbsp;

## Synopsis
#### 1)
```cpp
struct IntegerComponents {
    const std::string_view digits = xieite::strings::characters::alphanumeric;
    const std::string_view negatives = "-";
    const std::string_view positives = "+";
    const std::string_view points = ".";
    const std::string_view exponents = "Ee";
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
