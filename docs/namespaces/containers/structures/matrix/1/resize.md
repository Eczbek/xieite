# [xieite](../../../../../../xieite.md)\:\:[containers](../../../../../../containers.md)\:\:[Matrix<Value_>](../../../../matrix.md)\:\:resize\<\>\(\)
Defined in header [<xieite/containers/matrix.hpp>](../../../../../../../include/xieite/containers/matrix.hpp)

&nbsp;

## Description
Resizes the matrix and reinterprets the underlying data.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::RangeOf<std::size_t> Range_>
constexpr std::optional<std::monostate> resize(Range_&& dimensions) noexcept;
```
#### 2)
```cpp
template<std::convertible_to<std::size_t>... Sizes_>
constexpr std::optional<std::monostate> resize(Sizes_... dimensions) noexcept;
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

    matrix.resize(3, 2);

    std::println("");
    for (std::size_t x = 0; x < 3; ++x) {
        for (std::size_t y = 0; y < 2; ++y) {
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

1 2
3 4
5 6
```
