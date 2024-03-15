# [xieite](../../xieite.md)\:\:[strings](../../strings.md)\:\:validNumber
Defined in header [<xieite/strings/valid_number.hpp>](../../../include/xieite/strings/valid_number.hpp)

&nbsp;

## Description
Checks if a string can be parsed a number from.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Arithmetic Number>
[[nodiscard]] constexpr bool validNumber(std::string_view value) noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/strings/valid_number.hpp"

int main() {
    std::println("{}", xieite::strings::validNumber("3.14159"));
    std::println("{}", xieite::strings::validNumber("test"));
}
```
Output:
```
true
false
```
