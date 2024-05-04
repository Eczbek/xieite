# [xieite](../../xieite.md)\:\:[algorithms](../../algorithms.md)\:\:findOccurrence\<\>\(\)
Defined in header [<xieite/algorithms/find_occurrence.hpp>](../../../include/xieite/algorithms/find_occurrence.hpp)

&nbsp;

## Description
Finds a specific occurrence of a value in a range and returns an iterator pointing to it, or the end if the value is not found.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::ranges::range Range_, xieite::concepts::Functable<bool(std::ranges::range_reference_t<Range_>, std::ranges::range_reference_t<Range_>)> Functor_ = std::ranges::equal_to>
[[nodiscard]] constexpr std::ranges::const_iterator_t<Range_> findOccurrence(Range_& range, std::size_t count, std::ranges::range_reference_t<Range_> value, Functor_&& comparator = Functor_())
noexcept(xieite::concepts::NoThrowInvocable<Functor_, std::ranges::range_reference_t<Range_>, std::ranges::range_reference_t<Range_>>);
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

    auto result = xieite::algorithms::findOccurrence(values, 3, 1);

    std::println("{}", std::ranges::distance(values.begin(), result));
}
```
Output:
```
6
```
