# xieite::math::isNaN
Defined in header `<xieite/math/isNaN.hpp>`

<br/>

Checks whether a value is NaN. Unlike `std::isnan`, this is `constexpr`.

<br/><br/>

## Declarations
```cpp
template<xieite::concepts::Arithmetic N>
[[nodiscard]]
constexpr bool isNaN(const N value) noexcept;
```

<br/><br/>

## Example
```cpp
#include <cmath> // std::sqrt
#include <iostream> // std::boolalpha, std::cout
#include <xieite/math/isNaN.hpp>
#include <xieite/math/squareRoot.hpp>

constexpr bool result = xieite::math::isNaN(xieite::math::squareRoot<double>(-1));

int main() {
	std::cout << std::boolalpha << result << '\n';
}
```
Output:
```
true
```
