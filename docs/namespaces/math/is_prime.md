# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:isPrime\(\)
Defined in header [<xieite/math/is_prime.hpp>](../../../include/xieite/math/is_prime.hpp)

&nbsp;

## Description
Checks whether an integer is only evenly divisible by itself and 1.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::integral Integral>
[[nodiscard]] constexpr bool isPrime(Integral value) noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/math/is_prime.hpp"

int main() {
    std::println("{}", xieite::math::isPrime(17));
}
```
Output:
```
true
```
