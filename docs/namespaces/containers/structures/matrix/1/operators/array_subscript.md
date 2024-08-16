# [xieite](../../../../../../xieite.md)\:\:[containers](../../../../../../containers.md)\:\:[Matrix<Value>](../../../../matrix.md)\:\:operator\[\]\<\>\(\)
Defined in header [<xieite/containers/matrix.hpp>](../../../../../../../include/xieite/containers/matrix.hpp)

&nbsp;

## Description
Accesses a value by indices for every dimension.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Self, std::ranges::input_range Range>
requires(std::convertible_to<std::ranges::range_value_t<Range>, std::size_t>)
[[nodiscard]] constexpr auto&& operator[](this Self&&, Range&& indices);
```
#### 2)
```cpp
template<typename Self, std::convertible_to<std::size_t>... Sizes>
[[nodiscard]] constexpr auto&& operator[](this Self&&, Sizes... indices);
```

&nbsp;

## Example
```cpp
#include <cstddef>
#include <print>
#include "xieite/containers/matrix.hpp"

int main() {
    xieite::containers::Matrix<int> matrix = { 1, 2, 3, 4, 5, 6 };

    matrix.resize(2, 3);

    for (std::size_t x = 0; x < 2; ++x) {
        for (std::size_t y = 0; y < 3; ++y) {
            std::print("{} ", matrix[x, y]);
        }
        std::println();
    }
}
```
Output:
```
1 2 3
4 5 6
```
