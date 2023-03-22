# xieite::math::pi
Defined in header `<xieite/math/pi.hpp>`

<br/>

Defines integer values of Pi.

<br/><br/>

## Declarations
```cpp
template<std::floating_point FloatingPoint>
constexpr FloatingPoint pi<FloatingPoint> = std::numbers::pi_v<FloatingPoint>;
```
```cpp
template<std::integral Integral>
constexpr Integral pi<Integral> = 3;
```

<br/><br/>

## Example
```cpp
#include <iostream>
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
