# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:[BigInteger](../BigInteger.md)\:\:operator+
Defined in header [<xieite/math/BigInteger.hpp>](../../../include/xieite/math/BigInteger.hpp)

&nbsp;

## Synopses

&nbsp;

```cpp
[[nodiscard]]
constexpr xieite::math::BigInteger operator+() const noexcept;
```
#### Return type
- The same `xieite::math::BigInteger` with unchanged value

&nbsp;

```cpp
[[nodiscard]]
constexpr xieite::math::BigInteger operator+(const xieite::math::BigInteger& addend) const noexcept;
```
#### Function parameters
- `addend` - A `xieite::math::BigInteger` constant reference
#### Return type
- `xieite::math::BigInteger`

&nbsp;

```cpp
template<std::integral Integer>
[[nodiscard]]
constexpr xieite::math::BigInteger operator+(Integer addend) const noexcept;
```
#### Template parameters
- `Integer` - A type satisfying `std::integral`
#### Function parameters
- `addend` - - An `Integer`
#### Return type
- `xieite::math::BigInteger`

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/math/BigInteger.hpp>

int main() {
    std::cout << (xieite::math::BigInteger(9) + 3).string() << '\n';
}
```
Output:
```
12
```
