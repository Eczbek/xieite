# [`xieite`](../../../README.md)`::`[`math`](../../../docs/math.md)`::`[`BigInteger`](../../../docs/math/BigInteger.md)`::operator--`
Defined in header [`<xieite/math/BigInteger.hpp>`](../../../include/xieite/math/BigInteger.hpp)

<br/>

## Synopses

<br/><br/>

```cpp
constexpr xieite::math::BigInteger& operator--() noexcept;
```
### Return value
- The `xieite::math::BigInteger`

<br/><br/>

```cpp
constexpr xieite::math::BigInteger& operator--(int) noexcept;
```
### Return value
- The `xieite::math::BigInteger`

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/math/BigInteger.hpp>

int main() {
	xieite::math::BigInteger bigInteger = 7;

	std::cout << (--bigInteger).string() << '\n';
}
```
Output:
```
6
```
