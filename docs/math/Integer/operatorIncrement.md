# `xieite::math::Integer<bits, sign>::operator++`
Defined in header [`<xieite/math/Integer.hpp>`](https://github.com/Eczbek/xieite/tree/main/include/xieite/math/Integer.hpp)

<br/><br/>

## Synopsis

<br/>

```cpp
constexpr xieite::math::Integer<bits, sign> operator++() noexcept;
```
### Return value
- A `xieite::math::Integer` of `bits` and `sign`

<br/>

```cpp
constexpr xieite::math::Integer<bits, sign> operator++(int) noexcept;
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

	std::cout << ++integer << '\n';
}
```
Output:
```
6
```

<br/><br/>

## See also
- [`xieite::math::Integer`](https://github.com/Eczbek/xieite/tree/main/docs/math/Integer.md)
