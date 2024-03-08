# [xieite](../../xieite.md)\:\:[functors](../../functors.md)\:\:rotate
Defined in header [<xieite/functors/rotate.hpp>](../../../include/xieite/functors/rotate.hpp)

&nbsp;

## Description
Rotates variables.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type, typename... Types>
requires(!std::is_const_v<Type> && (... && !std::is_const_v<Types>))
constexpr void rotate(std::size_t distance, Type& first, Types&... rest) noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/functors/rotate.hpp"

int main() {
    int a = 0;
    int b = 1;
    int c = 2;
    int d = 4;
    int e = 5;
    std::println("{} {} {} {} {}", a, b, c, d, e);

    xieite::functors::rotate(1, a, b, c, d, e);
    std::println("{} {} {} {} {}", a, b, c, d, e);

    xieite::functors::rotate(2, a, b, c, d, e);
    std::println("{} {} {} {} {}", a, b, c, d, e);
}
```
Output:
```
0 1 2 3 4
1 2 4 5 0
4 5 0 1 2
```
