# [xieite](../../xieite.md)\:\:[algorithms](../../algorithms.md)\:\:modes\<\>\(\)
Defined in header [<xieite/algorithms/modes.hpp>](../../../include/xieite/algorithms/modes.hpp)

&nbsp;

## Description
Computes the modes (or antimodes) of a set of data.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::ranges::range Range_, xieite::concepts::Functable<bool(std::ranges::range_const_reference_t<Range_>, std::ranges::range_const_reference_t<Range_>)> Functor_ = std::ranges::greater>
requires(xieite::concepts::Arithmetic<std::ranges::range_value_t<Range_>> && xieite::concepts::ConstantInvocable<Functor_, std::ranges::range_const_reference_t<Range_>, std::ranges::range_const_reference_t<Range_>>)
[[nodiscard]] constexpr std::vector<std::ranges::iterator_t<Range_>> modes(Range_& range, Functor_&& comparator = Functor_())
noexcept(xieite::concepts::NoThrowInvocable<Functor_, std::ranges::range_const_reference_t<Range_>, std::ranges::range_const_reference_t<Range_>>);
```

&nbsp;

## Example
```cpp
#include <print>
#include <vector>
#include "xieite/algorithms/nodes.hpp"

int main() {
    std::vector<int> data { 1, 3, 2, 4, 5 };

    for (auto iterator : xieite::algorithms::modes(data)) {
        std::println("{}", *iterator);
    }
}
```
Output:
```
3
5
```
