# [xieite](../../../README.md)::[math](../../math.md)::[BigInteger](../BigInteger.md)::operator/
Defined in header [<xieite/math/BigInteger.hpp>](../../../include/xieite/math/BigInteger.hpp)

<br/><br/>

## Synopses

<br/><br/>

```cpp
[[nodiscard]]
constexpr xieite::math::BigInteger operator/(const xieite::math::BigInteger& bigInteger) const noexcept;
```
### Parameters
- `bigInteger` - A `xieite::math::BigInteger` constant reference
### Return value
- A `xieite::math::BigInteger`

<br/><br/>

```cpp
[[nodiscard]]
constexpr xieite::math::BigInteger operator/(std::integral auto value) const noexcept;
```
### Parameters
- `value` - An `auto` copy, satisfying `std::integral`
### Return value
- A `xieite::math::BigInteger`

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/math/BigInteger.hpp>

int main() {
	std::cout << (xieite::math::BigInteger(9) / 3).string() << '\n';
}
```
Output:
```
3
```
