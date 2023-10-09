# [xieite](../../../../../xieite.md)\:\:[math](../../../../../math.md)\:\:[BigInteger<Datum>](../../../../big_integer.md)\:\:operator++
Defined in header [<xieite/math/big_integer.hpp>](../../../../../../../include/xieite/math/big_integer.hpp)

&nbsp;

## Synopses
#### 1)
```cpp
constexpr xieite::math::BigInteger<Datum>& operator++() noexcept;
```
#### 2)
```cpp
constexpr xieite::math::BigInteger<Datum>& operator++(int) noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/math/big_integer.hpp>

int main() {
    xieite::math::BigInteger<Datum> bigInteger = 7;

    std::cout << (++bigInteger).string() << '\n';
}
```
Output:
```
8
```
