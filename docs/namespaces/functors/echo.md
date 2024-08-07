# [xieite](../../xieite.md)\:\:[functors](../../functors.md)\:\:Echo \{\}
Defined in header [<xieite/functors/echo.hpp>](../../../include/xieite/functors/echo.hpp)

&nbsp;

## Description
Functor that returns whatever it is given.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Target_>
struct Echo {
    template<typename Type_>
    constexpr decltype(auto) operator()(Type_&&) const noexcept;
};
```
- [operator\(\)\<\>\(\)](./structures/echo/1/operators/call.md)

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/functors/echo.hpp"

int main() {
    std::println("{}", xieite::functors::Echo()(4));
}
```
Output:
```
4
```
