# [xieite](../../xieite.md)\:\:[algorithms](../../algorithms.md)\:\:occurrence\<\>\(\)
Defined in header [<xieite/algorithms/occurrence.hpp>](../../../include/xieite/algorithms/occurrence.hpp)

&nbsp;

## Description
Finds a specific occurrence of a functor accepting an item of a range and returning `true`, and returns an iterator pointing to it, or the end if the occurrence is not found.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::ranges::range Range_, xieite::concepts::Functable<bool(std::ranges::range_reference_t<Range_>)> Functor_>
[[nodiscard]] constexpr std::ranges::const_iterator_t<Range_> occurrence(Range_& range, std::size_t count, Functor_&& selector = Functor_())
noexcept(xieite::concepts::NoThrowInvocable<Functor_, std::ranges::range_reference_t<Range_>>);
```

&nbsp;

## Example
```cpp
#include <iterator>
#include <print>
#include <vector>
#include "xieite/algorithms/occurrence.hpp"

int main() {
    //               indices: 0  1  2  3  4  5  6
    std::vector<int> values { 1, 2, 1, 3, 1, 4, 1 };
    //           occurrences: 0     1     2     3

    auto result = xieite::algorithms::occurrence(values, 3, [](int value) {
        return value == 1;
    });

    std::println("{}", std::ranges::distance(values.begin(), result));
}
```
Output:
```
6
```
