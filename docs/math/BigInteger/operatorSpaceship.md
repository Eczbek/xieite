# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:[BigInteger](../BigInteger.md)\:\:operator/
Defined in header [<xieite/math/BigInteger.hpp>](../../../include/xieite/math/BigInteger.hpp)

&nbsp;

## Synopses
#### 1)
```cpp
constexpr std::strong_ordering operator<=>(const xieite::math::BigInteger& comparand) const noexcept;
```
#### 2)
```cpp
template<std::integral Integer>
constexpr std::strong_ordering operator<=>(Integer comparand) const noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/math/BigInteger.hpp>

int main() {
    std::cout
        << std::boolalpha
        << (xieite::math::BigInteger(9) > 3) << '\n';
}
```
Output:
```
true
```
