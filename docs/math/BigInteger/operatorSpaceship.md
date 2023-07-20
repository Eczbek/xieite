# [xieite](../../xieite.md)::[math](../../math.md)::[BigInteger](../BigInteger.md)::operator/
Defined in header [<xieite/math/BigInteger.hpp>](../../../include/xieite/math/BigInteger.hpp)

<br/><br/>

## Synopses

<br/><br/>

```cpp
[[nodiscard]]
constexpr std::strong_ordering operator<=>(const xieite::math::BigInteger& comparand) const noexcept;
```
### Parameters
- `comparand` - A `xieite::math::BigInteger` constant reference
### Return value
- A `std::strong_ordering`

<br/><br/>

```cpp
[[nodiscard]]
constexpr std::strong_ordering operator<=>(std::integral auto comparand) const noexcept;
```
### Parameters
- `comparand` - A value of any type satisfying `std::integral`
### Return value
- A `std::strong_ordering`

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/math/BigInteger.hpp>

int main() {
	std::cout
		<< std::boolalpha
		<< (xieite::math::BigInteger(9) > 3) << '\n';
}
```
Output:
```
true
```
