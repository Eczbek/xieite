# `xieite::math::isPrime`
Defined in header [`<xieite/math/isPrime.hpp>`](https://github.com/Eczbek/xieite/tree/main/include/xieite/math/isPrime.hpp)

<br/>

Checks whether an integer is only evenly divisible by itself and 1.

<br/><br/>

## Synopsis

<br/>

```cpp
template<std::integral Integral>
[[nodiscard]]
constexpr bool isPrime(Integral value) noexcept;
```
### Template parameters
- `Integral` - An integral type, satisfying `std::integral`
### Parameters
- `value` - An `Integral` copy
### Return value
- A `bool`, whether or not `value` is prime

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/math/isPrime.hpp>

int main() {
	std::cout << std::boolalpha
		<< xieite::math::isPrime(17) << '\n';
}
```
Output:
```
true
```
