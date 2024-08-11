# [xieite](../../../../../../xieite.md)\:\:[containers](../../../../../../containers.md)\:\:[Matrix<Value_>](../../../../matrix.md)\:\:operator\[\]\<\>\(\)
Defined in header [<xieite/containers/matrix.hpp>](../../../../../../../include/xieite/containers/matrix.hpp)

&nbsp;

## Description
Accesses a value by indices for every dimension.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Self_, xieite::concepts::RangeOf<std::size_t> Range_>
[[nodiscard]] constexpr std::optional<std::reference_wrapper<xieite::types::MaybeConstant<Value_, std::is_const_v<Self_>>>> operator[](this Self_&&, Range_&& indices);
```
#### 2)
```cpp
template<typename Self_, std::convertible_to<std::size_t>... Sizes_>
[[nodiscard]] constexpr std::optional<std::reference_wrapper<xieite::types::MaybeConstant<Value_, std::is_const_v<Self_>>>> operator[](this Self_&&, Sizes_... indices);
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
        std::println();
    }
}
```
Output:
```
1 2 3
4 5 6
```
