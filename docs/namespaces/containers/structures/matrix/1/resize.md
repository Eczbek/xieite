# [xieite](../../../../../../xieite.md)\:\:[containers](../../../../../../containers.md)\:\:[Matrix<Value>](../../../../matrix.md)\:\:resize\(\)
Defined in header [<xieite/containers/matrix.hpp>](../../../../../../../include/xieite/containers/matrix.hpp)

&nbsp;

## Description
Resizes the matrix and reinterprets the underlying data. May throw `std::out_of_range` if the new dimensions require more data than what is provided.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::RangeOf<std::size_t> Range>
constexpr void resize(Range&& dimensions);
```
#### 2)
```cpp
template<std::convertible_to<std::size_t>... Sizes>
constexpr void resize(const Sizes... dimensions);
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

    matrix.resize(3, 2);

    std::println("");
    for (std::size_t x = 0; x < 3; ++x) {
        for (std::size_t y = 0; y < 2; ++y) {
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

1 2
3 4
5 6
```
