# [`xieite`](../../README.md)`::`[`math`](../../docs/math.md)`::minimalBits`
Defined in header [`<xieite/math/minimalBits.hpp>`](../../include/xieite/math/minimalBits.hpp)

<br/>

Calculates the minimmum amount of bits needed to store a value.

<br/><br/>

## Synopsis

<br/><br/>

```cpp
template<std::integral Integral>
[[nodiscard]]
constexpr std::size_t minimalBits(const Integral value) noexcept;
```
### Template parameters
- `Integral` - A type satisfying `std::integral`
### Parameters
- `value` - An `Integral` copy
### Return value
- A `std::size_t`, the number of bits

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/math/minimalBits.hpp>

int main() {
	std::cout
		<< xieite::math::minimalBits(0b101)
		<< '\n'
		<< xieite::math::minimalBits(0b110110)
		<< '\n';
}
```
Output:
```
3
6
```
