# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:antimodes\<\>\(\)
Defined in header [<xieite/math/antimodes.hpp>](../../../include/xieite/math/antimodes.hpp)

&nbsp;

## Description
Finds values which are less than both their direct neighbors.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::ranges::range Range_>
requires(xieite::concepts::Arithmetic<std::ranges::range_value_t<Range_>>)
[[nodiscard]] constexpr std::vector<std::ranges::range_value_t<Range_>> antimodes(const Range_& range) noexcept;
```
#### 2)
```cpp
template<xieite::concepts::Arithmetic... Arithmetics_>
[[nodiscard]] constexpr std::vector<std::common_type_t<double, Arithmetics_...>> antimodes(Arithmetics_... values) noexcept;
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
