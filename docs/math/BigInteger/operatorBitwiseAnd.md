# `xieite::math::BigInteger::operator&`
Defined in header `<xieite/math/BigInteger.hpp>`

<br/><br/>

## Synopses

<br/>

```cpp
[[nodiscard]]
constexpr xieite::math::BigInteger operator&(const xieite::math::BigInteger& bigInteger) const noexcept;
```
### Parameters
- `bigInteger` - A `xieite::math::BigInteger` constant reference
### Return value
- A `xieite::math::BigInteger`

<br/>

```cpp
[[nodiscard]]
constexpr xieite::math::BigInteger operator&(std::integral auto value) const noexcept;
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
	std::cout << (xieite::math::BigInteger(9) & 3).string() << '\n';
}
```
Output:
```
1
```

<br/><br/>

## See also
- [`xieite::math::BigInteger`](https://github.com/Eczbek/xieite/tree/main/docs/math/BigInteger.md)
