# [xieite](../../xieite.md)\:\:[algorithms](../../algorithms.md)\:\:findMostConsecutive\(\)
Defined in header [<xieite/algorithms/find_most_consecutive.hpp>](../../../include/xieite/algorithms/find_most_consecutive.hpp)

&nbsp;

## Description
Finds the subrange of greatest length containing the maximum number of consecutive values. If no matching values are found, returns a subrange where both iterators are set to the range's end.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::ranges::range Range, xieite::concepts::Functable<bool(std::ranges::range_const_reference_t<Range>, std::ranges::range_const_reference_t<Range>)> Comparator = std::ranges::equal_to>
[[nodiscard]] constexpr std::ranges::subrange<std::ranges::iterator_t<Range>> findMostConsecutive(Range&& range, std::ranges::range_const_reference_t<Range> value, Comparator&& comparator = Comparator()) noexcept;
```

&nbsp;

## Example
```cpp
#include <iterator>
#include <print>
#include <vector>
#include "xieite/algorithms/find_most_consecutive.hpp"

int main() {
    //               indices: 0  1  2  3  4  5  6  7
    std::vector<int> values { 1, 0, 1, 1, 1, 0, 1, 1 };
    //           consecutive: 1     1  2  3     1  2

    auto result = xieite::algorithms::findMostConsecutive(values, 1);

    std::println("{} - {}", std::ranges::distance(values.begin(), result.begin()), std::ranges::distance(values.begin(), result.end()));
}
```
Output:
```
2 - 5
```
