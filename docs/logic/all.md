# [xieite](../xieite.md)\:\:[logic](../logic.md)\:\:all
Defined in header [<xieite/logic/all.hpp>](../../include/xieite/logic/all.hpp)

&nbsp;

## Description
Checks whether all passed arguments are true. Expects all arguments to be converible to a boolean value.

&nbsp;

## Synopses
#### 1)
```cpp
template<std::convertible_to<bool>... Values>
constexpr bool all(const Values&... values)
noexcept(noexcept((std::is_nothrow_convertible_v<Values, bool> && ...)));
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/logic/all.hpp>

int main() {
    std::cout
        << std::boolalpha
        << xieite::logic::all(4, true, '$') << '\n';
}
```
Output:
```
true
```
