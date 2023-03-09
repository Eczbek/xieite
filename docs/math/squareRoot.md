# xieite::math::squareRoot
Defined in header `<xieite/math/squareRoot.hpp>`

<br/>

Calculates the square root of a value. Unlike `std::sqrt`, this is `constexpr`.

<br/><br/>

## Declarations
```cpp
template<xieite::concepts::Arithmetic N>
[[nodiscard]]
constexpr N squareRoot(const N value) noexcept;
```

<br/><br/>

## Example
```cpp
#include <iostream> // std::cout
#include <xieite/math/squareRoot.hpp>

constexpr double result = xieite::math::squareRoot(2.25);

int main() {
	std::cout << result << '\n';
}
```
Output:
```
1.5
```
