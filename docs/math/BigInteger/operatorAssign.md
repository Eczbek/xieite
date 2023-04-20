# `xieite::math::BigInteger::operator=`
Defined in header `<xieite/math/BigInteger.hpp>`

<br/><br/>

## Synopses

<br/>

```cpp
constexpr xieite::math::BigInteger& operator=(const xieite::math::BigInteger& bigInteger) const noexcept;
```
### Parameters
- `bigInteger` - A `xieite::math::BigInteger` constant reference
### Return value
- The `xieite::math::BigInteger`

<br/>

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

<br/><br/>

## See also
- [`xieite::math::BigInteger`](https://github.com/Eczbek/xieite/tree/main/docs/math/BigInteger.md)
