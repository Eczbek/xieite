# gcufl::math::approxEqual
Declared in `<gcufl/math/approxEqual.hpp>`
```cpp
template<gcufl::concepts::Arithmetic N>
constexpr bool approxEqual(const N value1, const N value2) noexcept;
```
Checks whether two numbers are almost the same.
<br/>
This can be used to ignore rounding errors.
## Example
```cpp
#include <gcufl/math/approxEqual.hpp>
#include <iostream>

int main() {
	const double a = 0.3;
	const double b = 0.1 + 0.2;
	
	std::cout.precision(17);
	std::cout << a << '\n'
		<< b << '\n'
		<< std::boolalpha << gcufl::math::approxEqual(a, b) << '\n';
}
```
Output:
```
0.29999999999999999
0.30000000000000004
true
```
