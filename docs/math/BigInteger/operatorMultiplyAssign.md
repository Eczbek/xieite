# [xieite](../../xieite.md)::[math](../../math.md)::[BigInteger](../BigInteger.md)::operator*=
Defined in header [<xieite/math/BigInteger.hpp>](../../../include/xieite/math/BigInteger.hpp)

<br/><br/>

## Synopses

<br/><br/>

```cpp
constexpr xieite::math::BigInteger& operator*=(const xieite::math::BigInteger& multiplicand) noexcept;
```
### Parameters
- `multiplicand` - A `xieite::math::BigInteger` constant reference
### Return value
- The `xieite::math::BigInteger`

<br/><br/>

```cpp
template<std::integral Integral>
constexpr xieite::math::BigInteger& operator*=(Integral multiplicand) noexcept;
```
### Template parameters
- `Integral` - A type satisfying `std::integral`
### Parameters
- `multiplicand` - - An `Integral`
### Return value
- The `xieite::math::BigInteger`

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/math/BigInteger.hpp>

int main() {
	xieite::math::BigInteger bigInteger = 9;

	bigInteger *= 3;

	std::cout << bigInteger.string() << '\n';
}
```
Output:
```
27
```
