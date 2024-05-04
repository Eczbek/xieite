# [xieite](../../../../../../xieite.md)\:\:[containers](../../../../../../containers.md)\:\:[Matrix<Value_>](../../../../matrix.md)\:\:Matrix\<\>\(\)
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
template<xieite::concepts::RangeOf<Value_> Range_>
constexpr Matrix(Range_&& range) noexcept;
```
#### 3)
```cpp
constexpr Matrix(std::initializer_list<Value_> list) noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/containers/matrix.hpp"

int main() {
    xieite::containers::Matrix<int> matrix = { 1, 2, 3, 4, 5, 6 };

    matrix.resize(2, 3);

    std::println("{}", matrix[1, 0].value());
}
```
Output:
```
4
```
