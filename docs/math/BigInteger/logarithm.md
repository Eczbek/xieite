# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:[BigInteger](../BigInteger.md)\:\:logarithm
Defined in header [<xieite/math/BigInteger.hpp>](../../../include/xieite/math/BigInteger.hpp)

&nbsp;

## Description
Calculates the logarithm of a `xieite::math::BigInteger` to a base

&nbsp;

## Synopses

&nbsp;

```cpp
[[nodiscard]]
constexpr xieite::math::BigInteger logarithm(const xieite::math::BigInteger& base) const;
```
#### Function parameters
- `base` - A `xieite::math::BigInteger`
#### Return type
- `xieite::math::BigInteger`

&nbsp;

```cpp
template<std::integral Integer>
[[nodiscard]]
constexpr xieite::math::BigInteger logarithm(Integer base) const;
```
#### Template parameters
- `Integer` - A type satisfying `std::integral`
#### Function parameters
- `base` - An `Integer`
#### Return type
- `xieite::math::BigInteger`

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/math/BigInteger.hpp>

int main() {
    xieite::math::BigInteger bigInteger = 1000;

    std::cout << bigInteger.logarithm(10).string() << '\n';
}
```
Output:
```
3
```
