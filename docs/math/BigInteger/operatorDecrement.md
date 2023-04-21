# `xieite::math::BigInteger::operator--`
Defined in header [`<xieite/math/BigInteger.hpp>`](../../../include/xieite/math/BigInteger.hpp)

<br/><br/>

## Synopses

<br/>

```cpp
constexpr xieite::math::BigInteger& operator--() noexcept;
```
### Return value
- The `xieite::math::BigInteger`

<br/>

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

<br/><br/>

## See also
- [`xieite::math::BigInteger`](../../../docs/math/BigInteger.md)
