# `xieite::math::BigInteger::operator<<=`
Defined in header [`<xieite/math/BigInteger.hpp>`](../../../include/xieite/math/BigInteger.hpp)

<br/><br/>

## Synopses

<br/>

```cpp
constexpr xieite::math::BigInteger& operator<<=(const xieite::math::BigInteger& bigInteger) noexcept;
```
### Parameters
- `bigInteger` - A `xieite::math::BigInteger` constant reference
### Return value
- The `xieite::math::BigInteger`

<br/>

```cpp
constexpr xieite::math::BigInteger& operator<<=(std::integral auto value) noexcept;
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
	xieite::math::BigInteger bigInteger = 9;

	bigInteger <<= 3;

	std::cout << bigInteger.string() << '\n';
}
```
Output:
```
72
```

<br/><br/>

## See also
- [`xieite::math::BigInteger`](../../../docs/math/BigInteger.md)
