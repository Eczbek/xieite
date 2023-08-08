# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:[BigInteger](../BigInteger.md)\:\:operator=
Defined in header [<xieite/math/BigInteger.hpp>](../../../include/xieite/math/BigInteger.hpp)

&nbsp;

## Synopses

&nbsp;

```cpp
constexpr xieite::math::BigInteger& operator=(const xieite::math::BigInteger& value) const noexcept;
```
#### Function parameters
- `value` - A `xieite::math::BigInteger` constant reference
#### Return type
- The `xieite::math::BigInteger`

&nbsp;

```cpp
template<std::integral Integer>
constexpr xieite::math::BigInteger& operator=(Integer value) const noexcept;
```
#### Template parameters
- `Integer` - A type satisfying `std::integral`
#### Function parameters
- `value` - - An `Integer`
#### Return type
- The `xieite::math::BigInteger`

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/math/BigInteger.hpp>

int main() {
    xieite::math::BigInteger bigInteger = 17;

    bigInteger = 41;

    std::cout << bigInteger.string() << '\n';
}
```
Output:
```
41
```
