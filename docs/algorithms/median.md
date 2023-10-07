# [xieite](../xieite.md)\:\:[algorithms](../algorithms.md)\:\:median
Defined in header [<xieite/algorithms/median.hpp>](../../include/xieite/algorithms/median.hpp)

&nbsp;

## Description
Computes the median of a set of data.

&nbsp;

## Synopses
#### 1)
```cpp
template<std::ranges::range Range>
requires(xieite::concepts::Numeric<std::ranges::range_value_t<Range>>)
[[nodiscard]] constexpr xieite::math::Result<std::ranges::range_value_t<Range>> median(const Range& range) noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <vector>
#include <xieite/algorithms/median.hpp>

int main() {
    std::vector<int> data { 1, 1, 2, 2, 5 };

    std::cout << xieite::algorithms::median(data) << '\n';
}
```
Output:
```
2
```
