# xieite::math::isPrime
Defined in header `<xieite/math/isPrime.hpp>`

<br/>

Checks whether an integral is prime, or only divisible by itself and 1.

<br/><br/>

## Declarations
```cpp
template<std::integral Integral>
[[nodiscard]]
constexpr bool isPrime(const Integral value) noexcept;
```

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/math/isPrime.hpp>

int main() {
	std::cout << std::boolalpha << xieite::math::isPrime(17) << '\n';
}
```
Output:
```
true
```
