# xieite::math::isPrime
Declared in `<xieite/math/isPrime.hpp>`
```cpp
template<std::integral N>
[[nodiscard]]
constexpr bool isPrime(const N value) noexcept;
```
Checks whether an integral is prime.
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
