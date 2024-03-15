# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:mergeIntervals\(\)
Defined in header [<xieite/math/merge_intervals.hpp>](../../../include/xieite/math/merge_intervals.hpp)

&nbsp;

## Description
Merges intervals if they overlap.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Arithmetic Number, xieite::concepts::RangeOf<xieite::math::Interval<Number>> IntervalRange>
[[nodiscard]] constexpr std::vector<xieite::math::Interval<Number>> mergeIntervals(IntervalRange&& intervals) noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/math/interval.hpp"
#include "xieite/math/merge_intervals.hpp"

int main() {
    std::vector<xieite::math::Interval<int>> intervals = {
        xieite::math::Interval<int>(1, 3),
        xieite::math::Interval<int>(2, 4),
        xieite::math::Interval<int>(5, 7)
    };

    for (xieite::math::Interval<int> interval : xieite::math::mergeIntervals<int>(intervals)) {
        std::println("{}-{}", interval.start, interval.end);
    }
}
```
Output:
```
1-4
5-7
```
