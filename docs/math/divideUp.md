# [xieite](../xieite.md)\:\:[math](../math.md)\:\:divideUp
Defined in header [<xieite/math/divideUp.hpp>](../../include/xieite/math/divideUp.hpp)

&nbsp;

## Description
Computes the value of a division and rounds away from zero.

&nbsp;

## Synopses
#### 1)
```cpp
template<std::integral Integer>
constexpr Integer divideUp(const Integer dividend, const Integer divisor) noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/math/divideUp.hpp>

int main() {
    std::cout << xieite::math::divideUp(-249, 16) << '\n';
}
```
Output:
```
-16
```