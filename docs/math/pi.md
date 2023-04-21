# [`xieite`](../../README.md)`::`[`math`](../../docs/math.md)`::pi`
Defined in header [`<xieite/math/pi.hpp>`](../../include/xieite/math/pi.hpp)

<br/>

Defines integer values of Pi.

<br/><br/>

## Synopses

<br/>

```cpp
template<std::floating_point FloatingPoint>
constexpr FloatingPoint pi<FloatingPoint> = std::numbers::pi_v<FloatingPoint>;
```
### Template parameters
- `FloatingPoint` - A floating point type, satisfying `std::floating_point`

<br/>

```cpp
template<std::integral Integral>
constexpr Integral pi<Integral> = 3;
```
### Template parameters
- `Integral` - An integral type, satisfying `std::integral`

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/math/pi.hpp>

int main() {
	std::cout
		<< xieite::math::pi<double>
		<< '\n'
		<< xieite::math::pi<int>
		<< '\n';
}
```
Output:
```
3.14159
3
```
