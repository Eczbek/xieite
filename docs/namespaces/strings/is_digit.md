# [xieite](../../xieite.md)\:\:[strings](../../strings.md)\:\:isDigit
Defined in header [<xieite/strings/is_digit.hpp>](../../../include/xieite/strings/is_digit.hpp)

&nbsp;

## Description
Checks if a character is a digit.

&nbsp;

## Synopses
#### 1)
```cpp
[[nodiscard]] constexpr bool isDigit(char character) noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/strings/is_digit.hpp>

int main() {
    std::cout
        << std::boolalpha
        << xieite::strings::isDigit('3')
		<< '\n';
}
```
Output:
```
true
```
