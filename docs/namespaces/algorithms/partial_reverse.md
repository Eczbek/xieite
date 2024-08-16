# [xieite](../../xieite.md)\:\:[algorithms](../../algorithms.md)\:\:partialReverse\<\>\(\)
Defined in header [<xieite/algorithms/partial_reverse.hpp>](../../../include/xieite/algorithms/partial_reverse.hpp)

&nbsp;

## Description
Selects iterators and then reverses them only between themselves.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::ranges::input_range Range, xieite::concepts::Functor<bool(std::ranges::range_reference_t<Range>)> Functor>
requires(!std::is_const_v<Range>)
constexpr void partialReverse(Range& range, Functor&& selector)
noexcept(xieite::concepts::NoThrowInvocable<Functor, std::ranges::range_reference_t<Range>>);
```

&nbsp;

## Example
```cpp
#include <array>
#include <print>
#include "xieite/algorithms/partial_reverse.hpp"

int main() {
    std::array<int, 5> values { 1, 2, 3, 4, 5 };

    auto callback = [](int value) -> bool {
        return value <= 3;
    };

    xieite::algorithms::partialReverse(values, callback);

    for (int value : values) {
        std::print("{} ", value);
    }
    std::println();
}
```
Output:
```
3 2 1 4 5
```
