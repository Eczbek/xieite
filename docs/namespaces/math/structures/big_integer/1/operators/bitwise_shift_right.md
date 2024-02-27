# [xieite](../../../../../xieite.md)\:\:[math](../../../../../math.md)\:\:[BigInteger<Word>](../../../../big_integer.md)\:\:operator>>
Defined in header [<xieite/math/big_integer.hpp>](../../../../../../../include/xieite/math/big_integer.hpp)

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] friend constexpr xieite::math::BigInteger<Word> operator>>(const xieite::math::BigInteger<Word>& leftOperand, const xieite::math::BigInteger<Word>& rightOperand) noexcept;
```
#### 2)
```cpp
template<std::integral Integer>
[[nodiscard]] friend constexpr xieite::math::BigInteger<Word> operator>>(const xieite::math::BigInteger<Word>& leftOperand, const Integer rightOperand) noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include "xieite/math/big_integer.hpp"

int main() {
    std::cout << (xieite::math::BigInteger(9) >> 3).string() << '\n';
}
```
Output:
```
1
```
