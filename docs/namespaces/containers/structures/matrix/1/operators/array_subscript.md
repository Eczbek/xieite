# [xieite](../../../../../../xieite.md)\:\:[containers](../../../../../../containers.md)\:\:[Matrix<Value>](../../../../matrix.md)\:\:operator\[\]\(\)
Defined in header [<xieite/containers/matrix.hpp>](../../../../../../../include/xieite/containers/matrix.hpp)

&nbsp;

## Description
Accesses a value by indices for every dimension. May throw `std::out_of_range` if the number of indices does not match the number of dimensions, or `std::range_error` if an index is outside its respective dimension.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Self, xieite::concepts::RangeOf<std::size_t> Range>
[[nodiscard]] constexpr auto&& operator[](this Self&& self, Range&& indices);
```
#### 2)
```cpp
template<typename Self, std::convertible_to<std::size_t>... Sizes>
[[nodiscard]] constexpr auto&& operator[](this Self&& self, const Sizes... indices);
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
        std::println("");
    }
}
```
Output:
```
1 2 3
4 5 6
```
