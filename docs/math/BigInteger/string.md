# [xieite](../../../README.md)::[math](../../math.md)::[BigInteger](../BigInteger.md)::string
Defined in header [<xieite/math/BigInteger.hpp>](../../../include/xieite/math/BigInteger.hpp)

<br/>

Converts a `xieite::math::BigInteger` to a `std::string`

<br/><br/>

## Synopsis

<br/>

```cpp
[[nodiscard]]
constexpr std::string string() const noexcept;
```
### Return value
- A `std::string`

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/math/BigInteger.hpp>

int main() {
	std::cout << xieite::math::BigInteger(418).string() << '\n';
}
```
Output:
```
418
```
