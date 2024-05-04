# [xieite](../../xieite.md)\:\:[algorithms](../../algorithms.md)\:\:mostConsecutive\<\>\(\)
Defined in header [<xieite/algorithms/most_consecutive.hpp>](../../../include/xieite/algorithms/most_consecutive.hpp)

&nbsp;

## Description
Finds the subrange of greatest length containing the maximum number of consecutive invocations of a functor returning `true`. If no functors return `true`, returns a subrange where both iterators are set to the range's end.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::ranges::range Range_, xieite::concepts::Functable<bool(std::ranges::range_const_reference_t<Range_>)> Functor_>
[[nodiscard]] constexpr std::ranges::subrange<std::ranges::iterator_t<Range_>> mostConsecutive(Range_&& range, Functor_&& selector = Functor_())
noexcept(xieite::concepts::NoThrowInvocable<Functor_, std::ranges::range_const_reference_t<Range_>>);
```

&nbsp;

## Example
```cpp
#include <iterator>
#include <print>
#include <vector>
#include "xieite/algorithms/most_consecutive.hpp"

int main() {
    //               indices: 0  1  2  3  4  5  6  7
    std::vector<int> values { 1, 0, 1, 1, 1, 0, 1, 1 };
    //           consecutive: 1     1  2  3     1  2

    auto result = xieite::algorithms::mostConsecutive(values, [](int value) {
        return value == 1;
    });

    std::println("{} - {}", std::ranges::distance(values.begin(), result.begin()), std::ranges::distance(values.begin(), result.end()));
}
```
Output:
```
2 - 5
```
