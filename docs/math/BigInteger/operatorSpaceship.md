# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:[BigInteger<Datum>](../BigInteger.md)\:\:operator/
Defined in header [<xieite/math/BigInteger.hpp>](../../../include/xieite/math/BigInteger.hpp)

&nbsp;

## Synopses
#### 1)
```cpp
friend constexpr std::strong_ordering operator<=>(const xieite::math::BigInteger<Datum>& leftComparand, const xieite::math::BigInteger<Datum>& rightComparand) noexcept;
```
#### 2)
```cpp
template<std::integral Integer>
friend constexpr std::strong_ordering operator<=>(const xieite::math::BigInteger<Datum>& leftComparand, const Integer rightComparand) noexcept;
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
