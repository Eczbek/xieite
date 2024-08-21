# [xieite](../../xieite.md)\:\:[algorithms](../../algorithms.md)\:\:modes\<\>\(\)
Defined in header [<xieite/algorithms/modes.hpp>](../../../include/xieite/algorithms/modes.hpp)

&nbsp;

## Description
Computes the modes (or antimodes) of a set of data.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::ranges::input_range Range, xieite::concepts::Functor<bool(std::ranges::range_reference_t<Range>, std::ranges::range_reference_t<Range>)> Functor = std::ranges::greater>
requires(xieite::concepts::Arithmetic<std::ranges::range_value_t<Range>> && xieite::concepts::ConstantInvocable<Functor, std::ranges::range_reference_t<Range>, std::ranges::range_reference_t<Range>>)
[[nodiscard]] constexpr std::vector<std::ranges::iterator_t<Range>> modes(Range& range, Functor&& comparator = Functor())
noexcept(std::is_nothrow_invocable_v<Functor, std::ranges::range_reference_t<Range>, std::ranges::range_reference_t<Range>>);
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
