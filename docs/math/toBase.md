# xieite::math::toBase
Defined in header `<xieite/math/toBase.hpp>`

<br/>

Converts an integer to a string in any base. Can be used as a compile-time method of stringifying integers.

<br/><br/>

## Declarations
```cpp
template<std::integral Integral = int>
[[nodiscard]]
constexpr std::string toBase(Integral value, std::size_t base, std::string_view digits = "0123456789abcdefghijklmnopqrstuvwxyz") noexcept;
```

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/math/toBase.hpp>

int main() {
	std::cout << xieite::math::toBase(12, 2) << '\n';
}
```
Output:
```
1100
```
