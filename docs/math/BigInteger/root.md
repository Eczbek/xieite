# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:[BigInteger](../BigInteger.md)\:\:root
Defined in header [<xieite/math/BigInteger.hpp>](../../../include/xieite/math/BigInteger.hpp)

&nbsp;

## Description
Calculates any root of a `xieite::math::BigInteger`

&nbsp;

## Synopses

&nbsp;

```cpp
[[nodiscard]]
constexpr xieite::math::BigInteger root(const xieite::math::BigInteger& degree) const;
```
#### Function parameters
- `degree` - A `xieite::math::BigInteger`
#### Return type
- `xieite::math::BigInteger`

&nbsp;

```cpp
template<std::integral Integer>
[[nodiscard]]
constexpr xieite::math::BigInteger root(Integer degree) const;
```
#### Template parameters
- `Integer` - A type satisfying `std::integral`
#### Function parameters
- `degree` - An `Integer`
#### Return type
- `xieite::math::BigInteger`

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/math/BigInteger.hpp>

int main() {
    xieite::math::BigInteger bigInteger = 8;

    std::cout << bigInteger.root(3).string() << '\n';
}
```
Output:
```
2
```
