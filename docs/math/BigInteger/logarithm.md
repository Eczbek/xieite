# [xieite](../../../README.md)::[math](../../math.md)::[BigInteger](../BigInteger.md)::logarithm
Defined in header [<xieite/math/BigInteger.hpp>](../../../include/xieite/math/BigInteger.hpp)

<br/>

Calculates the logarithm of a `xieite::math::BigInteger` to a base

<br/><br/>

## Synopses

<br/><br/>

```cpp
[[nodiscard]]
constexpr xieite::math::BigInteger logarithm(const xieite::math::BigInteger& base) const;
```
### Parameters
- `base` - A `xieite::math::BigInteger` copy
### Return value
- A `xieite::math::BigInteger`

<br/><br/>

```cpp
[[nodiscard]]
constexpr xieite::math::BigInteger logarithm(std::integral auto base) const;
```
### Parameters
- `base` - An `auto` integer type, satisfying `std::integral`
### Return value
- A `xieite::math::BigInteger`

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/math/BigInteger.hpp>

int main() {
	xieite::math::BigInteger bigInteger = 1000;

	std::cout << bigInteger.logarithm(10).string() << '\n';
}
```
Output:
```
3
```
