# `xieite::math::BigInteger::operator~`
Defined in header `<xieite/math/BigInteger.hpp>`

<br/><br/>

## Synopsis

<br/>

```cpp
[[nodiscard]]
constexpr xieite::math::BigInteger operator~() const noexcept;
```
### Return value
- A `xieite::math::BigInteger`

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/math/BigInteger.hpp>

int main() {
	std::cout << (~xieite::math::BigInteger(3)).string() << '\n';
}
```
Output:
```
-4
```

<br/><br/>

## See also
- [`xieite::math::BigInteger`](https://github.com/Eczbek/xieite/tree/main/docs/math/BigInteger.md)
