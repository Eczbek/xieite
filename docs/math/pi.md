# xieite::math::pi
Defined in header `<xieite/math/pi.hpp>`

<br/>

Defines integer values of Pi.

<br/><br/>

## Definitions
```cpp
template<std::floating_point N>
constexpr N pi = std::numbers::pi_v<N>;
```
```cpp
template<std::integral N>
constexpr N pi = 3;
```

<br/><br/>

## Example
```cpp
#include <iostream> // std::cout
#include <xieite/math/pi.hpp>

int main() {
	std::cout
		<< xieite::math::pi<double> << '\n'
		<< xieite::math::pi<int> << '\n';
}
```
Output:
```
3.14159
3
```
