# xieite::math::absolute
Defined in header `<xieite/math/absolute.hpp>`

<br/>

Returns the absolute of a value. Unlike `std::abs`, this works for both signed and unsigned arithmetic types.

<br/><br/>

## Declarations
```cpp
template<xieite::concepts::Arithmetic Number>
[[nodiscard]]
constexpr Number absolute(const Number value) noexcept;
```

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/math/absolute.hpp>

int main() {
	int a = -17;
	unsigned int b = 4;
	
	std::cout << xieite::math::absolute(a) << '\n'
		<< xieite::math::absolute(b) << '\n';
}
```
Output:
```
17
4
```
