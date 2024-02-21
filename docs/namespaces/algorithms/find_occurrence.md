# [xieite](../../xieite.md)\:\:[algorithms](../../algorithms.md)\:\:findOccurrence
Defined in header [<xieite/algorithms/find_occurrence.hpp"](../../../include/xieite/algorithms/find_occurrence.hpp)

&nbsp;

## Description
Finds a specific occurrence of a value in a range and returns an iterator pointing to it, or the end if the value is not found.

&nbsp;

## Synopses
#### 1)
```cpp
template<std::ranges::range Range, std::convertible_to<std::ranges::range_value_t<Range>> Value, xieite::concepts::Functable<bool(std::ranges::range_reference_t<Range>, std::ranges::range_reference_t<Range>)> Functor = std::ranges::equal_to>
[[nodiscard]] constexpr std::ranges::const_iterator_t<Range> findOccurrence(Range& range, Value&& value, std::size_t count, Functor&& comparator = Functor())
noexcept(xieite::concepts::NoThrowInvocable<Functor, std::ranges::range_reference_t<Range>, std::ranges::range_reference_t<Range>>);
```

&nbsp;

## Example
```cpp
#include <iterator>
#include <print>
#include <vector>
#include "xieite/algorithms/find_occurrence.hpp"

int main() {
    //               indices: 0  1  2  3  4  5  6
    std::vector<int> values { 1, 2, 1, 3, 1, 4, 1 };
    //           occurrences: 0     1     2     3

    auto result = xieite::algorithms::findOccurrence(values, 1, 3);

    std::println("{}", std::ranges::distance(values.begin(), result));
}
```
Output:
```
6
```
