# [xieite](../../xieite.md)::[math](../../math.md)::[BigInteger](../BigInteger.md)::operator-=
Defined in header [<xieite/math/BigInteger.hpp>](../../../include/xieite/math/BigInteger.hpp)

<br/><br/>

## Synopses

<br/><br/>

```cpp
constexpr xieite::math::BigInteger& operator-=(const xieite::math::BigInteger& subtrahend) noexcept;
```
### Parameters
- `subtrahend` - A `xieite::math::BigInteger` constant reference
### Return value
- The `xieite::math::BigInteger`

<br/><br/>

```cpp
constexpr xieite::math::BigInteger& operator-=(std::integral auto subtrahend) noexcept;
```
### Parameters
- `subtrahend` - A value of any type satisfying `std::integral`
### Return value
- The `xieite::math::BigInteger`

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/math/BigInteger.hpp>

int main() {
	xieite::math::BigInteger bigInteger = 9;

	bigInteger -= 3;

	std::cout << bigInteger.string() << '\n';
}
```
Output:
```
6
```
