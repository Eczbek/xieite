# [xieite](../../../../../../xieite.md)\:\:[containers](../../../../../../containers.md)\:\:[Matrix<Value_>](../../../../matrix.md)\:\:rotate\(\)
Defined in header [<xieite/containers/matrix.hpp>](../../../../../../../include/xieite/containers/matrix.hpp)

&nbsp;

## Description
Rotates a two-dimensional slice of a matrix 90 degrees.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::integral Integral_, xieite::concepts::RangeOf<std::size_t> Range_>
constexpr std::optional<std::monostate> rotate(Integral_ rotations, Range_&& indices) noexcept;
```
#### 2)
```cpp
template<std::integral Integral_, std::convertible_to<std::size_t>... Sizes_>
constexpr std::optional<std::monostate> rotate(Integral_ rotations, Sizes_... indices) noexcept;
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
            std::print("{} ", matrix[x, y].value());
        }
        std::println("");
    }

    matrix.rotate(1);

    std::println("");
    for (std::size_t x = 0; x < 3; ++x) {
        for (std::size_t y = 0; y < 2; ++y) {
            std::print("{} ", matrix[x, y].value());
        }
        std::println("");
    }

    matrix.rotate(-3);

    std::println("");
    for (std::size_t x = 0; x < 2; ++x) {
        for (std::size_t y = 0; y < 3; ++y) {
            std::print("{} ", matrix[x, y].value());
        }
        std::println("");
    }
}
```
Output:
```
1 2 3
4 5 6

4 1
5 2
6 3

6 5 4
3 2 1
```
