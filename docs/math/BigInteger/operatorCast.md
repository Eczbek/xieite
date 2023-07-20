# [xieite](../../xieite.md)::[math](../../math.md)::[BigInteger](../BigInteger.md)::operator typename
Defined in header [<xieite/math/BigInteger.hpp>](../../../include/xieite/math/BigInteger.hpp)

<br/>

Casts a `xieite::math::BigInteger` to any other arithmetic type

<br/><br/>

## Synopses

<br/><br/>

```cpp
template<xieite::concepts::Arithmetic Number>
[[nodiscard]]
constexpr operator Number() const noexcept;
```
### Template parameters
- `Number` - Any arithmetic type satisfying `xieite::concepts::Arithmetic`

<br/><br/>

```cpp
[[nodiscard]]
constexpr operator bool() const noexcept;
```

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/math/BigInteger.hpp>

int main() {
	std::cout
		<< std::boolalpha
		<< static_cast<bool>(xieite::math::BigInteger(4)) << '\n';
}
```
Output:
```
true
```
