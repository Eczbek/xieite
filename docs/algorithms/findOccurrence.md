# [xieite](../xieite.md)\:\:[algorithms](../algorithms.md)\:\:findOccurrence
Defined in header [<xieite/algorithms/findOccurrence.hpp>](../../include/xieite/algorithms/findOccurrence.hpp)

&nbsp;

## Description
Finds a specific occurrence of a value in a range and returns an iterator pointing to it or the end if it is not found.

&nbsp;

## Synopsis
```cpp
template<std::ranges::range Range, xieite::concepts::Functable<bool(std::ranges::range_value_t<Range>, std::ranges::range_value_t<Range>)> Callback = std::ranges::equal_to>
[[nodiscard]]
constexpr std::ranges::const_iterator_t<const Range&> findOccurrence(const Range& range, std::ranges::range_const_reference_t<Range> value, std::size_t count, const Callback& comparator = Callback());
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <iterator>
#include <vector>
#include <xieite/algorithms/findOccurrence.hpp>

int main() {
    std::vector<int> values { 1, 2, 1, 3, 1, 4, 1 };
    //                        0     1     2     3

    auto result = xieite::algorithms::findOccurrence(values, 1, 3);

    std::cout << std::ranges::distance(values.begin(), result) << '\n';
}
```
Output:
```
6
```
