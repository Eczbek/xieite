# [xieite](../../xieite.md)::[math](../../math.md)::[BigInteger](../BigInteger.md)::root
Defined in header [<xieite/math/BigInteger.hpp>](../../../include/xieite/math/BigInteger.hpp)

<br/>

Calculates any root of a `xieite::math::BigInteger`

<br/><br/>

## Synopses

<br/><br/>

```cpp
[[nodiscard]]
constexpr xieite::math::BigInteger root(const xieite::math::BigInteger& degree) const;
```
### Parameters
- `degree` - A `xieite::math::BigInteger`
### Return value
- A `xieite::math::BigInteger`

<br/><br/>

```cpp
template<std::integral Integral>
[[nodiscard]]
constexpr xieite::math::BigInteger root(Integral degree) const;
```
### Template parameters
- `Integral` - A type satisfying `std::integral`
### Parameters
- `degree` - An `Integral`
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
