# [xieite](../../../../../../xieite.md)\:\:[containers](../../../../../../containers.md)\:\:[Matrix<Value>](../../../../matrix.md)\:\:size\(\)
Defined in header [<xieite/containers/matrix.hpp>](../../../../../../../include/xieite/containers/matrix.hpp)

&nbsp;

## Description
Returns the matrix dimensions.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] constexpr const std::vector<std::size_t>& size() const noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/containers/matrix.hpp"

int main() {
    xieite::containers::Matrix<int> matrix = { 1, 2, 3, 4, 5, 6 };

    matrix.resize(2, 3);

    for (std::size_t dimension : matrix.size()) {
        std::print("{} ", dimension);
    }
    std::println("");
}
```
Output:
```
2 3
```
