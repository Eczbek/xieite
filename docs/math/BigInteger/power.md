# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:[BigInteger](../BigInteger.md)\:\:power
Defined in header [<xieite/math/BigInteger.hpp>](../../../include/xieite/math/BigInteger.hpp)

&nbsp;

## Description
Raises a `xieite::math::BigInteger` to an exponent

&nbsp;

## Synopses

&nbsp;

```cpp
[[nodiscard]]
constexpr xieite::math::BigInteger power(xieite::math::BigInteger exponent) const;
```
#### Function parameters
- `exponent` - A `xieite::math::BigInteger`
#### Return type
- `xieite::math::BigInteger`

&nbsp;

```cpp
template<std::integral Integer>
[[nodiscard]]
constexpr xieite::math::BigInteger power(Integer exponent) const;
```
#### Template parameters
- `Integer` - A type satisfying `std::integral`
#### Function parameters
- `exponent` - An `Integer`
#### Return type
- `xieite::math::BigInteger`

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/math/BigInteger.hpp>

int main() {
    xieite::math::BigInteger bigInteger = 2;

    std::cout << bigInteger.power(3).string() << '\n';
}
```
Output:
```
8
```
