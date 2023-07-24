# [xieite](../../xieite.md)::[math](../../math.md)::[BigInteger](../BigInteger.md)::operator>>
Defined in header [<xieite/math/BigInteger.hpp>](../../../include/xieite/math/BigInteger.hpp)

<br/><br/>

## Synopses

<br/><br/>

```cpp
[[nodiscard]]
constexpr xieite::math::BigInteger operator>>(const xieite::math::BigInteger& positions) const noexcept;
```
### Parameters
- `positions` - A `xieite::math::BigInteger` constant reference
### Return value
- A `xieite::math::BigInteger`

<br/><br/>

```cpp
template<std::integral Integral>
[[nodiscard]]
constexpr xieite::math::BigInteger operator>>(Integral positions) const noexcept;
```
### Template parameters
- `Integral` - A type satisfying `std::integral`
### Parameters
- `positions` - - An `Integral`
### Return value
- A `xieite::math::BigInteger`

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/math/BigInteger.hpp>

int main() {
	std::cout << (xieite::math::BigInteger(9) >> 3).string() << '\n';
}
```
Output:
```
1
```
