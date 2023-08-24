# [xieite](../xieite.md)\:\:[logic](../logic.md)\:\:any
Defined in header [<xieite/logic/any.hpp>](../../include/xieite/logic/any.hpp)

&nbsp;

## Description
Checks whether at least one passed argument is true. Expects all arguments to be converible to a boolean value.

&nbsp;

## Synopses
#### 1)
```cpp
template<std::convertible_to<bool>... Values>
constexpr bool any(const Values&... values)
noexcept(noexcept(xieite::concepts::NoThrowConvertibleToAllOf<bool, Values...>));
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/logic/any.hpp>

int main() {
    std::cout
        << std::boolalpha
        << xieite::logic::any(false, 0, '\0') << '\n';
}
```
Output:
```
false
```
