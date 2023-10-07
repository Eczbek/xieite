# [xieite](../../../../../xieite.md)\:\:[math](../../../../../math.md)\:\:[BigInteger<Datum>](../../../BigInteger.md)\:\:absolute
Defined in header [<xieite/math/BigInteger.hpp>](../../../../../../include/xieite/math/BigInteger.hpp)

&nbsp;

## Description
Gets the absolute value of a `xieite::math::BigInteger`.

&nbsp;

## Synopses
#### 1)
```cpp
[[nodiscard]] constexpr xieite::math::BigInteger<Datum> absolute() const noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/math/BigInteger.hpp>

int main() {
    xieite::math::BigInteger<Datum> bigInteger = -999;

    std::cout << bigInteger.absolute().string() << '\n';
}
```
Output:
```
999
```
