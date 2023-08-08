# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:[BigInteger](../BigInteger.md)\:\:operator++
Defined in header [<xieite/math/BigInteger.hpp>](../../../include/xieite/math/BigInteger.hpp)

&nbsp;

## Synopses

&nbsp;

```cpp
constexpr xieite::math::BigInteger& operator++() noexcept;
```
#### Return type
- The `xieite::math::BigInteger`

&nbsp;

```cpp
constexpr xieite::math::BigInteger& operator++(int) noexcept;
```
#### Function parameters
- unnamed `int`
#### Return type
- The `xieite::math::BigInteger`

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/math/BigInteger.hpp>

int main() {
    xieite::math::BigInteger bigInteger = 7;

    std::cout << (++bigInteger).string() << '\n';
}
```
Output:
```
8
```
