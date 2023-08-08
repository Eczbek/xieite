# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:[BigInteger](../BigInteger.md)\:\:operator|=
Defined in header [<xieite/math/BigInteger.hpp>](../../../include/xieite/math/BigInteger.hpp)

&nbsp;

## Synopses

&nbsp;

```cpp
constexpr xieite::math::BigInteger& operator|=(const xieite::math::BigInteger& operand) noexcept;
```
#### Function parameters
- `operand` - A `xieite::math::BigInteger` constant reference
#### Return type
- The `xieite::math::BigInteger`

&nbsp;

```cpp
template<std::integral Integer>
constexpr xieite::math::BigInteger& operator|=(Integer operand) noexcept;
```
#### Template parameters
- `Integer` - A type satisfying `std::integral`
#### Function parameters
- `operand` - - An `Integer`
#### Return type
- The `xieite::math::BigInteger`

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/math/BigInteger.hpp>

int main() {
    xieite::math::BigInteger bigInteger = 9;

    bigInteger |= 3;

    std::cout << bigInteger.string() << '\n';
}
```
Output:
```
11
```
