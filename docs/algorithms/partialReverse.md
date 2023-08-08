# [xieite](../xieite.md)\:\:[algorithms](../algorithms.md)\:\:partialReverse
Defined in header [<xieite/algorithms/partialReverse.hpp>](../../include/xieite/algorithms/partialReverse.hpp)

&nbsp;

## Description
Selects iterators and then reverses them only between themselves.

&nbsp;

## Synopsis
```cpp
template<std::ranges::range Range, xieite::concepts::Functable<bool(std::ranges::range_value_t<Range>)> Functable>
constexpr void partialReverse(const Range& range, const Functable& selector);
```

&nbsp;

## Example
```cpp
#include <array>
#include <iostream>
#include <xieite/algorithms/partialReverse.hpp>

int main() {
    std::array<int, 5> values { 1, 2, 3, 4, 5 };

    auto callback = [](int value) {
        return value <= 3;
    };

    xieite::algorithms::partialReverse(values, callback);

    for (int value : values) {
        std::cout << value << ' ';
    }
    std::cout << '\n';
}
```
Output:
```
3 2 1 4 5 
```
