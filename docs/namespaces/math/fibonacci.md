# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:fibonacci
Defined in header [<xieite/math/fibonacci.hpp>](../../../include/xieite/math/fibonacci.hpp)

&nbsp;

## Description
A lookup table of the fibonacci sequence.

&nbsp;

## Synopses
#### 1)
```cpp
inline constexpr auto fibonacci = /* std::array<std::size_t, N> { ... } */
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/math/fibonacci.hpp>

int main() {
    std::cout << xieite::math::fibonacci.at(45) << '\n';
}
```
Output:
```
1134903170
```
