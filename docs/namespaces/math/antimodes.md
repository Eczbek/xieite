# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:antimodes\<\>\(\)
Defined in header [<xieite/math/antimodes.hpp>](../../../include/xieite/math/antimodes.hpp)

&nbsp;

## Description
Finds values which are less than both their direct neighbors.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::ranges::input_range Range>
requires(xieite::concepts::Arithmetic<std::ranges::range_value_t<Range>>)
[[nodiscard]] constexpr std::vector<std::ranges::range_value_t<Range>> antimodes(const Range& range) noexcept;
```
#### 2)
```cpp
template<xieite::concepts::Arithmetic... Arithmetics>
[[nodiscard]] constexpr std::vector<std::common_type_t<double, Arithmetics...>> antimodes(Arithmetics... values) noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/math/antimodes.hpp"

int main() {
    for (int value : xieite::math::antimodes(1, 3, 2, 4, 5)) {
        std::println("{}", value);
    }
}
```
Output:
```
1
2
```
