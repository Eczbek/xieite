# [xieite](../../xieite.md)\:\:[algorithms](../../algorithms.md)\:\:mean
Defined in header [<xieite/algorithms/mean.hpp>](../../../include/xieite/algorithms/mean.hpp)

&nbsp;

## Description
Computes the mean of a set of data.

&nbsp;

## Synopses
#### 1)
```cpp
template<std::ranges::range Range>
requires(xieite::concepts::Numeric<std::ranges::range_value_t<Range>>)
[[nodiscard]] constexpr xieite::algorithms::Result<std::ranges::range_value_t<Range>> mean(const Range& range) noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <vector>
#include <xieite/algorithms/mean.hpp>

int main() {
    std::vector<int> data { 1, 1, 2, 2, 5 };

    std::cout << xieite::algorithms::mean(data) << '\n';
}
```
Output:
```
2.2
```
