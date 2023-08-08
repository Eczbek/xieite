# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:[BigInteger](../BigInteger.md)\:\:operator-
Defined in header [<xieite/math/BigInteger.hpp>](../../../include/xieite/math/BigInteger.hpp)

&nbsp;

## Synopses

&nbsp;

```cpp
[[nodiscard]]
constexpr xieite::math::BigInteger operator-() const noexcept;
```
#### Return type
- `xieite::math::BigInteger` of oppositely-negative value

&nbsp;

```cpp
[[nodiscard]]
constexpr xieite::math::BigInteger operator-(const xieite::math::BigInteger& subtrahend) const noexcept;
```
#### Function parameters
- `subtrahend` - A `xieite::math::BigInteger` constant reference
#### Return type
- `xieite::math::BigInteger`

&nbsp;

```cpp
template<std::integral Integer>
[[nodiscard]]
constexpr xieite::math::BigInteger operator-(Integer subtrahend) const noexcept;
```
#### Template parameters
- `Integer` - A type satisfying `std::integral`
#### Function parameters
- `subtrahend` - - An `Integer`
#### Return type
- `xieite::math::BigInteger`

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/math/BigInteger.hpp>

int main() {
    std::cout << (xieite::math::BigInteger(9) - 3).string() << '\n';
}
```
Output:
```
6
```
