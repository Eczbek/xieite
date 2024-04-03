# [xieite](../../xieite.md)\:\:[algorithms](../../algorithms.md)\:\:rotate\(\)
Defined in header [<xieite/algorithms/rotate.hpp>](../../../include/xieite/algorithms/rotate.hpp)

&nbsp;

## Description
Rotates individual variables.

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
#include "xieite/algorithms/rotate.hpp"

int main() {
    int a = 1;
    int b = 2;
    int c = 3;
    int d = 4;
    int e = 5;
    std::println("{} {} {} {} {}", a, b, c, d, e);

    xieite::algorithms::rotate(1, a, b, c, d, e);
    std::println("{} {} {} {} {}", a, b, c, d, e);

    xieite::algorithms::rotate(2, a, b, c, d, e);
    std::println("{} {} {} {} {}", a, b, c, d, e);
}
```
Output:
```
1 2 3 4 5
2 3 4 5 1
4 5 1 2 3
```
