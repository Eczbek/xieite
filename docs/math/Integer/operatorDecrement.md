# `xieite::math::Integer<bits, sign>::operator--`
Defined in header [`<xieite/math/Integer.hpp>`](../../../include/xieite/math/Integer.hpp)

<br/><br/>

## Synopsis

<br/>

```cpp
constexpr xieite::math::Integer<bits, sign> operator--() noexcept;
```
### Return value
- A `xieite::math::Integer` of `bits` and `sign`

<br/>

```cpp
constexpr xieite::math::Integer<bits, sign> operator--(int) noexcept;
```
### Return value
- A `xieite::math::Integer` of `bits` and `sign`

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/math/Integer.hpp>

int main() {
	xieite::math::Integer<4, false> integer = 5;

	std::cout << --integer << '\n';
}
```
Output:
```
4
```

<br/><br/>

## See also
- [`xieite::math::Integer`](../../../docs/math/Integer.md)
