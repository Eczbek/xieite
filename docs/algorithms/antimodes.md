# [xieite](../xieite.md)\:\:[algorithms](../algorithms.md)\:\:antimodes
Defined in header [<xieite/algorithms/antimodes.hpp>](../../include/xieite/algorithms/antimodes.hpp)

&nbsp;

## Description
Computes the antimodes of a set of data.

&nbsp;

## Synopses
#### 1)
```cpp
template<std::ranges::range Range, xieite::concepts::Functable<bool(std::ranges::range_value_t<Range>, std::ranges::range_value_t<Range>)> LesserComparator = std::ranges::less>
requires(xieite::concepts::Numeric<std::ranges::range_value_t<Range>>)
[[nodiscard]] constexpr std::vector<std::ranges::const_iterator_t<const Range&>> antimodes(const Range& range, LesserComparator lesserComparator = LesserComparator()) noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <vector>
#include <xieite/algorithms/antimodes.hpp>

int main() {
    std::vector<int> data { 1, 3, 2, 4, 5 };

    for (const auto iterator : xieite::algorithms::antimodes(data)) {
        std::cout << *iterator << '\n';
    }
}
```
Output:
```
1
2
```
