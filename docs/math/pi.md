# [xieite](../../README.md)::[math](../math.md)::pi
Defined in header [<xieite/math/pi.hpp>](../../include/xieite/math/pi.hpp)

<br/>

Defines integer values of Pi

<br/><br/>

## Synopses

<br/><br/>

```cpp
template<typename>
inline constexpr double pi = std::numbers::pi;
```
### Template parameters
- An unnamed unconstrained type

<br/><br/>

```cpp
template<std::floating_point FloatingPoint>
inline constexpr FloatingPoint pi<FloatingPoint> = std::numbers::pi_v<FloatingPoint>;
```
### Template parameters
- `FloatingPoint` - A floating point type, satisfying `std::floating_point`

<br/><br/>

```cpp
template<std::integral Integral>
inline constexpr Integral pi<Integral> = 3;
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
