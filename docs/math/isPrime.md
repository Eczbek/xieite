# xieite::math::isPrime
Defined in header `<xieite/math/isPrime.hpp>`

<br/>

Checks whether an integral is prime, or only divisible by itself and 1.

<br/><br/>

## Declaration
```cpp
template<std::integral N>
[[nodiscard]]
constexpr bool isPrime(const N value) noexcept;
```

<br/><br/>

## Example
```cpp
#include <iostream> // std::boolalpha, std::cout
#include <xieite/math/isPrime.hpp>

int main() {
	std::cout << std::boolalpha << xieite::math::isPrime(17) << '\n';
}
```
Output:
```
true
```
