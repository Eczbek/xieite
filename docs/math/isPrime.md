# xieite::math::isPrime
Declared in `<xieite/math/isPrime.hpp>`

<br/>

Checks whether an integral is prime.

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
