# [xieite](../xieite.md)\:\:[math](../math.md)\:\:median
Defined in header [<xieite/math/median.hpp>](../../include/xieite/math/median.hpp)

&nbsp;

## Description
Computes the median of some values. Returns `0` if no arguments are passed.

&nbsp;

## Synopses
#### 1)
```cpp
template<xieite::concepts::Numeric... Numbers>
[[nodiscard]] constexpr xieite::math::Result<Numbers...> median(const Numbers... values) noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/math/median.hpp>

int main() {
    std::cout << xieite::math::median(1, 1, 2, 2, 5) << '\n';
}
```
Output:
```
2
```
