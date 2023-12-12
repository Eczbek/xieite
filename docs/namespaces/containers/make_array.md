# [xieite](../../xieite.md)\:\:[containers](../../containers.md)\:\:makeArray
Defined in header [<xieite/containers/make_array.hpp>](../../../include/xieite/containers/make_array.hpp)

&nbsp;

## Description
Essentially attempts to create `std::array`s from other ranges.

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Value, std::size_t size, std::ranges::range Range>
requires(std::convertible_to<Value, std::ranges::range_value_t<Range>>)
[[nodiscard]] constexpr std::array<Value, size> makeArray(const Range& range) noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <vector>
#include <xieite/containers/make_array.hpp>

int main() {
    std::vector<int> source { 1, 2, 3, 4, 5 };

    auto target = xieite::containers::makeArray<int, 5>(source);

    for (int item : target) {
        std::cout << item << '\n';
    }
}
```
Output:
```
14
```
