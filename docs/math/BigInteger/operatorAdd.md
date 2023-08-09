# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:[BigInteger](../BigInteger.md)\:\:operator+
Defined in header [<xieite/math/BigInteger.hpp>](../../../include/xieite/math/BigInteger.hpp)

&nbsp;

## Synopses
#### 1)
```cpp
constexpr xieite::math::BigInteger operator+() const noexcept;
```
#### 2)
```cpp
constexpr xieite::math::BigInteger operator+(const xieite::math::BigInteger& addend) const noexcept;
```
#### 3)
```cpp
template<std::integral Integer>
constexpr xieite::math::BigInteger operator+(Integer addend) const noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/math/BigInteger.hpp>

int main() {
    std::cout << (xieite::math::BigInteger(9) + 3).string() << '\n';
}
```
Output:
```
12
```
