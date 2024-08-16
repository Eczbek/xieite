# [xieite](../../../../../../xieite.md)\:\:[containers](../../../../../../containers.md)\:\:[Matrix<Value>](../../../../matrix.md)\:\:Matrix\<\>\(\)
Defined in header [<xieite/containers/matrix.hpp>](../../../../../../../include/xieite/containers/matrix.hpp)

&nbsp;

## Description
Constructs a `xieite::containers::Matrix`.

&nbsp;

## Synopsis
#### 1)
```cpp
constexpr Matrix() noexcept;
```
#### 2)
```cpp
template<std::ranges::input_range Range>
requires(std::convertible_to<std::ranges::range_value_t<Range>, Value>)
explicit constexpr Matrix(Range&& range) noexcept;
```
#### 3)
```cpp
explicit(false) constexpr Matrix(std::initializer_list<Value> list) noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/containers/matrix.hpp"

int main() {
    xieite::containers::Matrix<int> matrix = { 1, 2, 3, 4, 5, 6 };

    matrix.resize(2, 3);

    std::println("{}", matrix[1, 0]);
}
```
Output:
```
4
```
