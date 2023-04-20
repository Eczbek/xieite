# `xieite::math::Integer<bits, sign>::operator-`
Defined in header [`<xieite/math/Integer.hpp>`](https://github.com/Eczbek/xieite/tree/main/include/xieite/math/Integer.hpp)

<br/><br/>

## Synopses

<br/>

```cpp
[[nodiscard]]
constexpr xieite::math::Integer<bits, sign> operator-() const noexcept;
```
### Return value
- A `xieite::math::Integer` of `bits` and `sign`

<br/>

```cpp
[[nodiscard]]
constexpr xieite::math::Integer<bits, sign> operator-(xieite::math::Integer<bits, sign> integer) const noexcept;
```
### Parameters
- `integer` - A `xieite::math::Integer` copy of `bits` and `sign`
### Return value
- A `xieite::math::Integer` of `bits` and `sign`

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/math/Integer.hpp>

int main() {
	std::cout << (xieite:math::Integer<4, false>(10) - 2) << '\n';
}
```
Output:
```
8
```

<br/><br/>

## See also
- [`xieite::math::Integer`](https://github.com/Eczbek/xieite/tree/main/docs/math/Integer.md)
