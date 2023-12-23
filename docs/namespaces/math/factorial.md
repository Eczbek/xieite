# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:factorial
Defined in header [<xieite/math/factorial.hpp>](../../../include/xieite/math/factorial.hpp)

&nbsp;

## Description
A lookup table of factorials.

&nbsp;

## Synopses
#### 1)
```cpp
inline constexpr auto factorial = /* std::array<std::size_t, N> { ... } */
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/math/factorial.hpp>

int main() {
    std::cout << xieite::math::factorial.at(17) << '\n';
}
```
Output:
```
355687428096000
```
