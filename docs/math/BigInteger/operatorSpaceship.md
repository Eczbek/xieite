# [`xieite`](../../../README.md)`::`[`math`](../../../docs/math.md)`::`[`BigInteger`](../../../docs/math/BigInteger.md)`::operator/`
Defined in header [`<xieite/math/BigInteger.hpp>`](../../../include/xieite/math/BigInteger.hpp)

<br/>

## Synopses

<br/><br/>

```cpp
[[nodiscard]]
constexpr std::strong_ordering operator<=>(const xieite::math::BigInteger& bigInteger) const noexcept;
```
### Parameters
- `bigInteger` - A `xieite::math::BigInteger` constant reference
### Return value
- A `std::strong_ordering`

<br/><br/>

```cpp
[[nodiscard]]
constexpr std::strong_ordering operator<=>(std::integral auto value) const noexcept;
```
### Parameters
- `value` - An `auto` copy, satisfying `std::integral`
### Return value
- A `std::strong_ordering`

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/math/BigInteger.hpp>

int main() {
	std::cout << std::boolalpha
		<< (xieite::math::BigInteger(9) > 3) << '\n';
}
```
Output:
```
true
```
