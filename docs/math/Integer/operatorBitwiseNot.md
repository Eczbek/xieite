# [`xieite`](../../../README.md)`::`[`math`](../../../docs/math.md)`::`[`Integer<bits, sign>`](../../../docs/math/Integer.md)`::operator~`
Defined in header [`<xieite/math/Integer.hpp>`](../../../include/xieite/math/Integer.hpp)

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
