# [xieite](../../xieite.md)::[math](../../math.md)::[BigInteger](../BigInteger.md)::power
Defined in header [<xieite/math/BigInteger.hpp>](../../../include/xieite/math/BigInteger.hpp)

<br/>

Raises a `xieite::math::BigInteger` to an exponent

<br/><br/>

## Synopses

<br/><br/>

```cpp
[[nodiscard]]
constexpr xieite::math::BigInteger power(xieite::math::BigInteger exponent) const;
```
### Parameters
- `exponent` - A `xieite::math::BigInteger`
### Return value
- A `xieite::math::BigInteger`

<br/><br/>

```cpp
template<std::integral Integral>
[[nodiscard]]
constexpr xieite::math::BigInteger power(Integral exponent) const;
```
### Template parameters
- `Integral` - A type satisfying `std::integral`
### Parameters
- `exponent` - An `Integral`
### Return value
- A `xieite::math::BigInteger`

<br/><br/>

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
