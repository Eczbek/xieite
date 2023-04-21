# [`xieite`](../../README.md)`::`[`math`](../../docs/math.md)`::alternatingBits`
Defined in header [`<xieite/math/alternatingBits.hpp>`](../../include/xieite/math/alternatingBits.hpp)

<br/><br/>

## Synopsis

<br/>

```cpp
template<std::integral Integral>
constexpr Integral alternatingBits = std::numeric_limits<Integral>::max() / 3;
```
### Template parameters
- `Integral` - Any integer type, satisfying `std::integral`

<br/><br/>

## Example
```cpp
#include <bitset>
#include <cstdint>
#include <iostream>
#include <xieite/math/alternatingBits.hpp>

int main() {
	std::bitset<32> bits = xieite::math::alternatingBits<std::uint32_t>;

	std::cout << bits << '\n';
}
```
Output:
```
01010101010101010101010101010101
```
