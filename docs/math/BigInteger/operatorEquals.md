# `xieite::math::BigInteger::operator/`
Defined in header `<xieite/math/BigInteger.hpp>`

<br/><br/>

## Synopses

<br/>

```cpp
[[nodiscard]]
constexpr bool operator==(const xieite::math::BigInteger& bigInteger) const noexcept;
```
### Parameters
- `bigInteger` - A `xieite::math::BigInteger` constant reference
### Return value
- A `bool`, whether or not the two values are equal

<br/>

```cpp
[[nodiscard]]
constexpr bool operator==(const std::integral auto value) const noexcept;
```
### Parameters
- `value` - An `auto` copy, satisfying `std::integral`
### Return value
- A `bool`, whether or not the two values are equal

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/math/BigInteger.hpp>

int main() {
	std::cout << std::boolalpha
		<< (xieite::math::BigInteger(2) == 2) << '\n';
}
```
Output:
```
true
```

<br/><br/>

## See also
- [`xieite::math::BigInteger`](https://github.com/Eczbek/xieite/tree/main/docs/math/BigInteger.md)
