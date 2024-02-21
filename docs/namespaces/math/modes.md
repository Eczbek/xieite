# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:modes
Defined in header [<xieite/math/modes.hpp"](../../../include/xieite/math/modes.hpp)

&nbsp;

## Description
Computes the modes of some values. Returns `{ 0 }` if no arguments are passed.

&nbsp;

## Synopses
#### 1)
```cpp
template<std::ranges::range Range>
requires(xieite::concepts::Arithmetic<std::ranges::range_value_t<Range>>)
[[nodiscard]] constexpr std::vector<std::ranges::range_value_t<Range>> modes(const Range& range) noexcept;
```
#### 2)
```cpp
template<xieite::concepts::Arithmetic... Numbers>
[[nodiscard]] constexpr std::vector<std::common_type_t<double, Numbers...>> modes(const Numbers... values) noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include "xieite/math/modes.hpp"

int main() {
    for (int value : xieite::math::modes(1, 3, 2, 4, 5)) {
        std::cout << value << '\n';
    }
}
```
Output:
```
3
5
```
