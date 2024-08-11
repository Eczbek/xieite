# [xieite](../../../../../../xieite.md)\:\:[containers](../../../../../../containers.md)\:\:[Matrix<Value_>](../../../../matrix.md)\:\:data\(\)
Defined in header [<xieite/containers/matrix.hpp>](../../../../../../../include/xieite/containers/matrix.hpp)

&nbsp;

## Description
Returns the underlying one-dimensional data.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] constexpr const std::vector<Value_>& data() const noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/containers/matrix.hpp"

int main() {
    xieite::containers::Matrix<int> matrix = { 1, 2, 3, 4, 5, 6 };

    matrix.resize(2, 3);

    for (int item : matrix.data()) {
        std::print("{} ", item);
    }
    std::println();

    matrix.rotate(1);

    for (int item : matrix.data()) {
        std::print("{} ", item);
    }
    std::println();
}
```
Output:
```
1 2 3 4 5 6
4 1 5 2 6 3
```
