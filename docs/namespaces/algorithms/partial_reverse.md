# [xieite](../../xieite.md)\:\:[algorithms](../../algorithms.md)\:\:partialReverse\<\>\(\)
Defined in header [<xieite/algorithms/partial_reverse.hpp>](../../../include/xieite/algorithms/partial_reverse.hpp)

&nbsp;

## Description
Selects iterators and then reverses them only between themselves.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::ranges::range Range_, xieite::concepts::Functable<bool(std::ranges::range_reference_t<Range_>)> Functor_>
requires(!std::is_const_v<Range_>)
constexpr void partialReverse(Range_& range, Functor_&& selector)
noexcept(xieite::concepts::NoThrowInvocable<Functor_, std::ranges::range_reference_t<Range_>>);
```

&nbsp;

## Example
```cpp
#include <array>
#include <print>
#include "xieite/algorithms/partial_reverse.hpp"

int main() {
    std::array<int, 5> values { 1, 2, 3, 4, 5 };

    auto callback = [](int value) {
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
