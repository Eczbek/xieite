# [`xieite`](../../../README.md)`::`[`math`](../../../docs/math.md)`::`[`BigInteger`](../../../docs/math/BigInteger.md)`::BigInteger`
Defined in header [`<xieite/math/BigInteger.hpp>`](../../../include/xieite/math/BigInteger.hpp)

<br/>

Constructs a `xieite::math::BigInteger`.

<br/><br/>

## Synopses

<br/><br/>

```cpp
template<std::integral Number>
constexpr BigInteger(Number value = 0) noexcept;
```
### Parameters
- `value` - An `auto` copy, satisfying `std::integral`

<br/><br/>

```cpp
constexpr BigInteger(const xieite::math::BigInteger& bigInteger) noexcept;
```
### Parameters
- `bigInteger` - A `xieite::math::BigInteger` constant reference

<br/><br/>

```cpp
constexpr BigInteger(const xieite::concepts::RangeOf<bool> auto& bits, bool sign = false) noexcept;
```
### Parameters
- `bits` - An `auto` constant reference, satisfying `xieite::concepts::RangeOf` of `bool`
- `sign` - A `bool` copy, determines whether the value is negative or positive

<br/><br/>

```cpp
constexpr BigInteger(std::string_view value);
```
### Parameters
- `value` - A `std::string_view` copy, which must consist of only digits and a `'-'`

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

<br/><br/>

## See also
- [`xieite::concepts::RangeOf`](../../../docs/concepts/RangeOf.md)
