# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:[BigInteger](../BigInteger.md)\:\:operator-
Defined in header [<xieite/math/BigInteger.hpp>](../../../include/xieite/math/BigInteger.hpp)

&nbsp;

## Synopses
#### 1)
```cpp
[[nodiscard]]
constexpr xieite::math::BigInteger operator-() const noexcept;
```
#### 2)
```cpp
[[nodiscard]]
constexpr xieite::math::BigInteger operator-(const xieite::math::BigInteger& subtrahend) const noexcept;
```
#### 3)
```cpp
template<std::integral Integer>
[[nodiscard]]
constexpr xieite::math::BigInteger operator-(Integer subtrahend) const noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/math/BigInteger.hpp>

int main() {
    std::cout << (xieite::math::BigInteger(9) - 3).string() << '\n';
}
```
Output:
```
6
```
