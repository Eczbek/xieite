# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:[BigInteger](../BigInteger.md)\:\:operator\<\<
Defined in header [<xieite/math/BigInteger.hpp>](../../../include/xieite/math/BigInteger.hpp)

&nbsp;

## Synopses

&nbsp;

```cpp
[[nodiscard]]
constexpr xieite::math::BigInteger operator<<(const xieite::math::BigInteger& positions) const noexcept;
```
#### Function parameters
- `positions` - A `xieite::math::BigInteger` constant reference
#### Return type
- `xieite::math::BigInteger`

&nbsp;

```cpp
template<std::integral Integer>
[[nodiscard]]
constexpr xieite::math::BigInteger operator<<(Integer positions) const noexcept;
```
#### Template parameters
- `Integer` - A type satisfying `std::integral`
#### Function parameters
- `positions` - - An `Integer`
#### Return type
- `xieite::math::BigInteger`

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/math/BigInteger.hpp>

int main() {
    std::cout << (xieite::math::BigInteger(9) << 3).string() << '\n';
}
```
Output:
```
72
```
