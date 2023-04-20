# `xieite::math::BigInteger::operator typename`
Defined in header [`<xieite/math/BigInteger.hpp>`](https://github.com/Eczbek/xieite/tree/main/include/xieite/math/BigInteger.hpp)

<br/>

Casts a `xieite::math::BigInteger` to any other arithmetic type.

<br/><br/>

## Synopses

<br/>

```cpp
template<xieite::concepts::Arithmetic Number>
[[nodiscard]]
constexpr operator Number() const noexcept;
```
### Template parameters
- `Number` - Any arithmetic type, satisfying `xieite::concepts::Arithmetic`

<br/>

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
	std::cout << std::boolalpha
		<< static_cast<bool>(xieite::math::BigInteger(4)) << '\n';
}
```
Output:
```
true
```

<br/><br/>

## See also
- [`xieite::concepts::Arithmetic`](https://github.com/Eczbek/xieite/tree/main/docs/concepts/Arithmetic.md)
- [`xieite::math::BigInteger`](https://github.com/Eczbek/xieite/tree/main/docs/math/BigInteger.md)
