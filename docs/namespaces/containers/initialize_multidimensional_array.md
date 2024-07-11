# [xieite](../../xieite.md)\:\:[containers](../../containers.md)\:\:initializeMultidimensionalArray\<\>\(\)
Defined in header [<xieite/containers/initialize_multidimensional_array.hpp>](../../../include/xieite/containers/initialize_multidimensional_array.hpp)

&nbsp;

## Description
Initializes a multidimensional `std::array` with a multidimensional `std::initializer_list`, like C-style arrays can be.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Value_>
[[nodiscard]] constexpr Value_ initializeMultidimensionalArray(const Value_& value) noexcept
```
#### 2)
```cpp
template<typename Value_, std::size_t firstDimension_, std::size_t... restDimensions_>
[[nodiscard]] constexpr xieite::types::FixedMatrix<std::array, Value_, firstDimension_, restDimensions_...> initializeMultidimensionalArray(xieite::types::DynamicMatrix<std::initializer_list, Value_, sizeof...(restDimensions_) + 1> list) noexcept;
```

&nbsp;

## Example
```cpp
#include <cstddef>
#include <print>
#include "xieite/containers/initialize_multidimensional_array.hpp"

int main() {
    auto data = xieite::containers::InitializeMultidimensionalArray<int, 2, 2>({
        { 1, 2 },
        { 3, 4 }
    });

    for (auto& row : data) {
        for (int item : row) {
            std::print("{} ", item);
        }
        std::println("");
    }
}
```
Output:
```
1 2 
3 4 
```
