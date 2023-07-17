# [xieite](../../xieite.md)::[math](../../math.md)::[BigInteger](../BigInteger.md)::operator++
Defined in header [<xieite/math/BigInteger.hpp>](../../../include/xieite/math/BigInteger.hpp)

<br/><br/>

## Synopses

<br/><br/>

```cpp
constexpr xieite::math::BigInteger& operator++() noexcept;
```
### Return value
- The `xieite::math::BigInteger`

<br/><br/>

```cpp
constexpr xieite::math::BigInteger& operator++(int) noexcept;
```
### Parameters
- An unnamed `int`
### Return value
- The `xieite::math::BigInteger`

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/math/BigInteger.hpp>

int main() {
	xieite::math::BigInteger bigInteger = 7;

	std::cout << (++bigInteger).string() << '\n';
}
```
Output:
```
8
```
