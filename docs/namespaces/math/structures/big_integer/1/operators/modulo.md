# [xieite](../../../../../xieite.md)\:\:[math](../../../../../math.md)\:\:[BigInteger<Word>](../../../../big_integer.md)\:\:operator%
Defined in header [<xieite/math/big_integer.hpp>](../../../../../../../include/xieite/math/big_integer.hpp)

&nbsp;

## Synopses
#### 1)
```cpp
[[nodiscard]] friend constexpr xieite::math::BigInteger<Word> operator%(const xieite::math::BigInteger<Word>& dividend, const xieite::math::BigInteger<Word>& divisor);
```
#### 2)
```cpp
template<std::integral Integer>
[[nodiscard]] friend constexpr xieite::math::BigInteger<Word> operator%(const xieite::math::BigInteger<Word>& dividend, const Integer divisor);
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/math/big_integer.hpp>

int main() {
    std::cout << (xieite::math::BigInteger(9) % 3).string() << '\n';
}
```
Output:
```
0
```
