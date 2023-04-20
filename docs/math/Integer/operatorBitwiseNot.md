# `xieite::math::Integer<bits, sign>::operator~`
Defined in header [`<xieite/math/Integer.hpp>`](https://github.com/Eczbek/xieite/tree/main/include/xieite/math/Integer.hpp)

<br/><br/>

## Synopsis

<br/>

```cpp
[[nodiscard]]
constexpr xieite::math::Integer<bits, sign> operator~() const noexcept;
```
### Return value
- A `xieite::math::Integer` of `bits` and `sign`

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/math/Integer.hpp>

int main() {
	std::cout << ~xieite:math::Integer<8, true>(5) << '\n';
}
```
Output:
```
-6
```

<br/><br/>

## See also
- [`xieite::math::Integer`](https://github.com/Eczbek/xieite/tree/main/docs/math/Integer.md)
