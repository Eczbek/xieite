# [xieite](../../xieite.md)\:\:[algorithms](../../algorithms.md)\:\:modes
Defined in header [<xieite/algorithms/modes.hpp>](../../../include/xieite/algorithms/modes.hpp)

&nbsp;

## Description
Computes the modes of a set of data.

&nbsp;

## Synopses
#### 1)
```cpp
template<std::ranges::range Range, xieite::concepts::Functable<bool(std::ranges::range_value_t<Range>, std::ranges::range_value_t<Range>)> GreaterComparator = std::ranges::greater>
requires(xieite::concepts::Numeric<std::ranges::range_value_t<Range>>)
[[nodiscard]] constexpr std::vector<std::ranges::const_iterator_t<const Range&>> modes(const Range& range, GreaterComparator greaterComparator = GreaterComparator()) noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <vector>
#include <xieite/algorithms/nodes.hpp>

int main() {
    std::vector<int> data { 1, 3, 2, 4, 5 };

    for (const auto iterator : xieite::algorithms::modes(data)) {
        std::cout << *iterator << '\n';
    }
}
```
Output:
```
3
5
```
