# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:fibonacci
Defined in header [<xieite/math/fibonacci.hpp>](../../../include/xieite/math/fibonacci.hpp)

&nbsp;

## Description
A lookup table of the fibonacci sequence.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Arithmetic Number>
inline constexpr auto fibonacci = /* std::array<Number, N> { ... } */
```

&nbsp;

## Example
```cpp
#include <iostream>
#include "xieite/math/fibonacci.hpp"

int main() {
    std::cout << xieite::math::fibonacci<std::size_t>[45] << '\n';
}
```
Output:
```
1134903170
```
