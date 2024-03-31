# [xieite](../../xieite.md)\:\:[strings](../../strings.md)\:\:isDigit\(\)
Defined in header [<xieite/strings/is_digit.hpp>](../../../include/xieite/strings/is_digit.hpp)

&nbsp;

## Description
Checks if a character is a digit.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] constexpr bool isDigit(char character) noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/strings/is_digit.hpp"

int main() {
    std::println("{}", xieite::strings::isDigit('3'));
}
```
Output:
```
true
```
