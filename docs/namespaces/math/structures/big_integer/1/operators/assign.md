# [xieite](../../../../../xieite.md)\:\:[math](../../../../../math.md)\:\:[BigInteger<Datum>](../../../../big_integer.md)\:\:operator=
Defined in header [<xieite/math/big_integer.hpp>](../../../../../../../include/xieite/math/big_integer.hpp)

&nbsp;

## Synopses
#### 1)
```cpp
constexpr xieite::math::BigInteger<Datum>& operator=(const xieite::math::BigInteger<Datum>& value) const noexcept;
```
#### 2)
```cpp
template<std::integral Integer>
constexpr xieite::math::BigInteger<Datum>& operator=(Integer value) const noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/math/big_integer.hpp>

int main() {
    xieite::math::BigInteger<Datum> bigInteger = 17;

    bigInteger = 41;

    std::cout << bigInteger.string() << '\n';
}
```
Output:
```
41
```
