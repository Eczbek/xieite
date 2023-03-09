# xieite::math::absolute
Defined in header `<xieite/math/absolute.hpp>`

<br/>

Returns the absolute of a value. Unlike `std::abs`, this is `constexpr` and works for both signed and unsigned arithmetic types.

<br/><br/>

## Declarations
```cpp
template<xieite::concepts::Arithmetic N>
[[nodiscard]]
constexpr N absolute(const N value) noexcept;
```

<br/><br/>

## Example
```cpp
#include <iostream> // std::cout
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
