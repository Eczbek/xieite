# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:median\<\>\(\)
Defined in header [<xieite/math/median.hpp>](../../../include/xieite/math/median.hpp)

&nbsp;

## Description
Computes the median of some values.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::ranges::input_range Range>
requires(xieite::concepts::Arithmetic<std::ranges::range_value_t<Range>>)
[[nodiscard]] constexpr std::common_type_t<double, std::ranges::range_value_t<Range>> median(Range range) noexcept;
```
#### 2)
```cpp
template<xieite::concepts::Arithmetic... Arithmetics>
requires(sizeof...(Arithmetics) > 0)
[[nodiscard]] constexpr std::common_type_t<double, Arithmetics...> median(Arithmetics... values) noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/math/median.hpp"

int main() {
    std::println("{}", xieite::math::median(1, 1, 2, 2, 5));
}
```
Output:
```
2
```
