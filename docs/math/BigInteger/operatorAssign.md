# [xieite](../../../README.md)::[math](../../math.md)::[BigInteger](../BigInteger.md)::operator=
Defined in header [<xieite/math/BigInteger.hpp>](../../../include/xieite/math/BigInteger.hpp)

<br/><br/>

## Synopses

<br/><br/>

```cpp
constexpr xieite::math::BigInteger& operator=(const xieite::math::BigInteger& value) const noexcept;
```
### Parameters
- `value` - A `xieite::math::BigInteger` constant reference
### Return value
- The `xieite::math::BigInteger`

<br/><br/>

```cpp
constexpr xieite::math::BigInteger& operator=(std::integral auto value) const noexcept;
```
### Parameters
- `value` - An `auto` copy, satisfying `std::integral`
### Return value
- The `xieite::math::BigInteger`

<br/><br/>

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
