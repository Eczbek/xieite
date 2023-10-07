# [xieite](../../xieite.md)\:\:[algorithms](../../algorithms.md)\:\:rotateMatrix
Defined in header [<xieite/algorithms/rotateMatrix.hpp>](../../../include/xieite/algorithms/rotateMatrix.hpp)

&nbsp;

## Description
Rotates a `std::vector` of at least 2 dimensions in 90* increments.

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Value>
[[nodiscard]] constexpr std::vector<std::vector<Value>> rotateMatrix(const std::vector<std::vector<Value>>& matrix, int rotations) noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <vector>
#include <xieite/algorithms/rotateMatrix.hpp>

int main() {
    std::vector<std::vector<int>> matrix {
        { 1, 2, 3 },
        { 4, 5, 6 }
    };

    for (std::vector<int>& row : xieite::algorithms::rotateMatrix(matrix, 1)) {
        for (int value : row) {
            std::cout << value << ' ';
        }
        std::cout << '\n';
    }
}
```
Output:
```
4 1
5 2
6 3
```
