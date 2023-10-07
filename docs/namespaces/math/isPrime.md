# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:isPrime
Defined in header [<xieite/math/isPrime.hpp>](../../../include/xieite/math/isPrime.hpp)

&nbsp;

## Description
Checks whether an integer is only evenly divisible by itself and 1.

&nbsp;

## Synopses
#### 1)
```cpp
template<std::integral Integer>
[[nodiscard]] constexpr bool isPrime(Integer value) noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/math/isPrime.hpp>

int main() {
    std::cout
        << std::boolalpha
        << xieite::math::isPrime(17) << '\n';
}
```
Output:
```
true
```
