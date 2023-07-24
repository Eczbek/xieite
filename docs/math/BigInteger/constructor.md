# [xieite](../../xieite.md)::[math](../../math.md)::[BigInteger](../BigInteger.md)::BigInteger
Defined in header [<xieite/math/BigInteger.hpp>](../../../include/xieite/math/BigInteger.hpp)

<br/>

Constructs a `xieite::math::BigInteger`

<br/><br/>

## Synopses

<br/><br/>

```cpp
template<std::integral Integral>
constexpr BigInteger(Integral value = 0) noexcept;
```
### Parameters
- `value` - - An `Integral`

<br/><br/>

```cpp
constexpr BigInteger(const xieite::math::BigInteger& value) noexcept;
```
### Parameters
- `value` - A `xieite::math::BigInteger` constant reference

<br/><br/>

```cpp
template<xieite::concepts::RangeOf<bool> BooleanRange>
constexpr BigInteger(const BooleanRange& bits, bool sign = false) noexcept;
```
### Template parameters
- `BooleanRange` - A type satisfying `xieite::concepts::RangeOf` of `bool`
### Parameters
- `bits` - A constant `BooleanRange` reference
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
