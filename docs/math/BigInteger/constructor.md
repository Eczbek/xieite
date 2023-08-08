# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:[BigInteger](../BigInteger.md)\:\:BigInteger
Defined in header [<xieite/math/BigInteger.hpp>](../../../include/xieite/math/BigInteger.hpp)

&nbsp;

## Description
Constructs a `xieite::math::BigInteger`

&nbsp;

## Synopses

&nbsp;

```cpp
template<std::integral Integer>
constexpr BigInteger(Integer value = 0) noexcept;
```
#### Function parameters
- `value` - - An `Integer`

&nbsp;

```cpp
constexpr BigInteger(const xieite::math::BigInteger& value) noexcept;
```
#### Function parameters
- `value` - A `xieite::math::BigInteger` constant reference

&nbsp;

```cpp
template<xieite::concepts::RangeOf<bool> BooleanRange>
constexpr BigInteger(const BooleanRange& bits, bool sign = false) noexcept;
```
#### Template parameters
- `BooleanRange` - A type satisfying `xieite::concepts::RangeOf` of `bool`
#### Function parameters
- `bits` - A constant `BooleanRange` reference
- `sign` - A `bool`, determines whether the value is negative or positive

&nbsp;

```cpp
constexpr BigInteger(std::string_view value);
```
#### Function parameters
- `value` - A `std::string_view`, which must consist of only digits may be preceded by a `'-'`

&nbsp;

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
