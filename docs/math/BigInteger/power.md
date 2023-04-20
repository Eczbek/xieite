# `xieite::math::BigInteger::power`
Defined in header `<xieite/math/BigInteger.hpp>`

<br/>

Raises a `xieite::math::BigInteger` to an exponent.

<br/><br/>

## Synopses

<br/>

```cpp
[[nodiscard]]
constexpr xieite::math::BigInteger power(xieite::math::BigInteger bigInteger) const;
```
### Parameters
- A `xieite::math::BigInteger` copy
### Return value
- A `xieite::math::BigInteger`

```cpp
[[nodiscard]]
constexpr xieite::math::BigInteger power(std::integral auto value) const;
```
### Parameters
- An `auto` integer type, satisfying `std::integral`
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

<br/><br/>

## See also
- [`xieite::math::BigInteger`](https://github.com/Eczbek/xieite/tree/main/docs/math/BigInteger.md)
