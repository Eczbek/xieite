# [xieite](../../../../../xieite.md)\:\:[math](../../../../../math.md)\:\:[BigInteger<Word>](../../../../big_integer.md)\:\:operator~
Defined in header [<xieite/math/big_integer.hpp>](../../../../../../../include/xieite/math/big_integer.hpp)

&nbsp;

## Synopses
#### 1)
```cpp
[[nodiscard]] constexpr xieite::math::BigInteger<Word> operator~() const noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/math/big_integer.hpp>

int main() {
    std::cout << (~xieite::math::BigInteger(3)).string() << '\n';
}
```
Output:
```
-4
```
