# [xieite](../../xieite.md)\:\:[strings](../../strings.md)\:\:isDigit
Defined in header [<xieite/strings/isDigit.hpp>](../../../include/xieite/strings/isDigit.hpp)

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
#include <xieite/strings/isDigit.hpp>

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
