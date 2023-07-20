# [xieite](../../xieite.md)::[math](../../math.md)::[BigInteger](../BigInteger.md)::BigInteger
Defined in header [<xieite/math/BigInteger.hpp>](../../../include/xieite/math/BigInteger.hpp)

<br/>

Constructs a `xieite::math::BigInteger`

<br/><br/>

## Synopses

<br/><br/>

```cpp
template<std::integral Number>
constexpr BigInteger(Number value = 0) noexcept;
```
### Parameters
- `value` - A value of any type satisfying `std::integral`

<br/><br/>

```cpp
constexpr BigInteger(const xieite::math::BigInteger& value) noexcept;
```
### Parameters
- `value` - A `xieite::math::BigInteger` constant reference

<br/><br/>

```cpp
constexpr BigInteger(const xieite::concepts::RangeOf<bool> auto& bits, bool sign = false) noexcept;
```
### Parameters
- `bits` - A constant reference to a value of any type satisfying `xieite::concepts::RangeOf` of `bool`
- `sign` - A `bool`, determines whether the value is negative or positive

<br/><br/>

```cpp
constexpr BigInteger(std::string_view value);
```
### Parameters
- `value` - A `std::string_view`, which must consist of only digits may be preceded by a `'-'`

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/math/BigInteger.hpp>

int main() {
	std::cout << xieite::math::BigInteger(416).string() << '\n';
}
```
Output:
```
416
```
