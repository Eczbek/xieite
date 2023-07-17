# [xieite](../../xieite.md)::[math](../../math.md)::[BigInteger](../BigInteger.md)::absolute
Defined in header [<xieite/math/BigInteger.hpp>](../../../include/xieite/math/BigInteger.hpp)

<br/>

Gets the absolute value of a `xieite::math::BigInteger`

<br/><br/>

## Synopsis

<br/>

```cpp
[[nodiscard]]
constexpr xieite::math::BigInteger absolute() const noexcept;
```
### Return value
- A `xieite::math::BigInteger`, the absolute value

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/math/BigInteger.hpp>

int main() {
	xieite::math::BigInteger bigInteger = -999;

	std::cout << bigInteger.absolute().string() << '\n';
}
```
Output:
```
999
```
