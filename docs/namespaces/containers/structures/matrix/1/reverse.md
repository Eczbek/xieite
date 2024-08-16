# [xieite](../../../../../../xieite.md)\:\:[containers](../../../../../../containers.md)\:\:[Matrix<Value>](../../../../matrix.md)\:\:reverse\(\)
Defined in header [<xieite/containers/matrix.hpp>](../../../../../../../include/xieite/containers/matrix.hpp)

&nbsp;

## Description
Reverses a dimension of the matrix. Using invalid indices invokes undefined behavior.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::ranges::input_range Range>
requires(std::convertible_to<std::ranges::range_value_t<Range>, std::size_t>)
constexpr void reverse(Range&& indices) noexcept;
```
#### 2)
```cpp
template<std::convertible_to<std::size_t>... Sizes>
constexpr void reverse(Sizes... indices) noexcept;
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

    matrix.reverse(0);

    std::println();
    for (std::size_t x = 0; x < 3; ++x) {
        for (std::size_t y = 0; y < 2; ++y) {
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

3 2 1
4 5 6
```
