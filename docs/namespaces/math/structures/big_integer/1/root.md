# [xieite](../../../../../xieite.md)\:\:[math](../../../../../math.md)\:\:[BigInteger<Datum>](../../../big_integer.md)\:\:root
Defined in header [<xieite/math/big_integer.hpp>](../../../../../../include/xieite/math/big_integer.hpp)

&nbsp;

## Description
Computes any root of a `xieite::math::BigInteger`.

&nbsp;

## Synopses
#### 1)
```cpp
[[nodiscard]] constexpr xieite::math::BigInteger<Datum> root(const xieite::math::BigInteger<Datum>& degree) const;
```
#### 2)
```cpp
template<std::integral Integer>
[[nodiscard]] constexpr xieite::math::BigInteger<Datum> root(Integer degree) const;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/math/big_integer.hpp>

int main() {
    xieite::math::BigInteger<Datum> bigInteger = 8;

    std::cout << bigInteger.root(3).string() << '\n';
}
```
Output:
```
2
```
