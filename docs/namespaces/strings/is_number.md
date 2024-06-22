# [xieite](../../xieite.md)\:\:[strings](../../strings.md)\:\:isNumber\<\>\(\)
Defined in header [<xieite/strings/is_number.hpp>](../../../include/xieite/strings/is_number.hpp)

&nbsp;

## Description
Checks if a string is a valid integral or fractional number.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Arithmetic Arithmetic_>
[[nodiscard]] constexpr bool isNumber(std::string_view value, std::conditional_t<std::floating_point<Arithmetic_>, xieite::math::SignedSize, Arithmetic_> radix = 10, xieite::strings::NumberComponents components = xieite::strings::NumberComponents()) noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/strings/is_number.hpp"

int main() {
    std::println("{}", xieite::strings::isNumber<int>("4"));
    std::println("{}", xieite::strings::isNumber<double>("-3.14159e22"));
    std::println("{}", xieite::strings::isNumber<double>("+DEAD.BEEF", 16));
    std::println("{}", xieite::strings::isNumber<int>("847ey5wi7"));
}
```
Output:
```
true
true
true
false
```
