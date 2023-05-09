# [`xieite`](../../../README.md)`::`[`math`](../../../docs/math.md)`::`[`BigInteger`](../../../docs/math/BigInteger.md)`::root`
Defined in header [`<xieite/math/BigInteger.hpp>`](../../../include/xieite/math/BigInteger.hpp)

<br/>

Calculates any root of a `xieite::math::BigInteger`.

<br/><br/>

## Synopses

<br/><br/>

```cpp
[[nodiscard]]
constexpr xieite::math::BigInteger root(const xieite::math::BigInteger& bigInteger) const;
```
### Parameters
- A `xieite::math::BigInteger` copy
### Return value
- A `xieite::math::BigInteger`

<br/><br/>

```cpp
[[nodiscard]]
constexpr xieite::math::BigInteger root(std::integral auto value) const;
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
	xieite::math::BigInteger bigInteger = 8;

	std::cout << bigInteger.root(3).string() << '\n';
}
```
Output:
```
2
```
