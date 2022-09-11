# gcufl::math::isPrime
Declared in `<gcufl/math/isPrime.hpp>`
```cpp
template <std::integral N>
constexpr bool isPrime(const N value) noexcept;
```
Checks whether an integral is prime.
## Example
```cpp
#include <gcufl/math/isPrime.hpp>
#include <iostream>

int main() {
	std::cout << std::boolalpha << gcufl::math::isPrime(17) << '\n';
}
```
Output:
```
true
```
