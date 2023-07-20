# [xieite](../xieite.md)::[math](../math.md)::reverse
Defined in header [<xieite/math/reverse.hpp>](../../include/xieite/math/reverse.hpp)

<br/>

Reverses an integral of any base

<br/><br/>

## Synopsis

<br/>

```cpp
template<std::integral Integral>
[[nodiscard]]
constexpr Integral reverse(Integral value, std::size_t base = 10) noexcept;
```
### Template parameters
- `Integral` - An integral type satisfying `std::integral`
### Parameters
- `value` - An `Integral`
- `base` - A `std::size_t`, set to `10` by default
### Return value
- An `Integral`

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/math/reverse.hpp>

int main() {
	std::cout << xieite::math::reverse(12345) << '\n';
}
```
Output:
```
54321
```
