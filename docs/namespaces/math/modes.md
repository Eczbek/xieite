# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:modes\(\)
Defined in header [<xieite/math/modes.hpp>](../../../include/xieite/math/modes.hpp)

&nbsp;

## Description
Finds values which are greater than both their direct neighbors.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::ranges::range Range>
requires(xieite::concepts::Arithmetic<std::ranges::range_value_t<Range>>)
[[nodiscard]] constexpr std::vector<std::ranges::range_value_t<Range>> modes(Range&& range) noexcept;
```
#### 2)
```cpp
template<xieite::concepts::Arithmetic... Numbers>
requires(sizeof...(Number) > 0)
[[nodiscard]] constexpr std::vector<std::common_type_t<double, Numbers...>> modes(Numbers... values) noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/math/modes.hpp"

int main() {
    for (int value : xieite::math::modes(1, 3, 2, 4, 5)) {
        std::println("{}", value);
    }
}
```
Output:
```
3
5
```
