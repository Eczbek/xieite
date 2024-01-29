# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:median
Defined in header [<xieite/math/median.hpp>](../../../include/xieite/math/median.hpp)

&nbsp;

## Description
Computes the median of some values. Returns `0` if no arguments are passed.

&nbsp;

## Synopses
#### 1)
```cpp
template<std::ranges::range Range>
requires(xieite::concepts::Arithmetic<std::ranges::range_value_t<Range>>)
[[nodiscard]] constexpr std::common_type_t<double, std::ranges::range_value_t<Range>> median(Range range) noexcept;
```
#### 2)
```cpp
template<xieite::concepts::Arithmetic... Numbers>
[[nodiscard]] constexpr std::common_type_t<double, Numbers...> median(const Numbers... values) noexcept;
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
