# [xieite](../../../../xieite.md)\:\:[math](../../../../math.md)\:\:[literals](../../literals.md)\:\:exponent
Defined in header [<xieite/math/literals/exponent.hpp>](../../../../../include/xieite/math/literals/exponent.hpp)

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] constexpr auto operator""_exponent(unsigned long long int value) noexcept;
```
#### 2)
```cpp
[[nodiscard]] constexpr auto operator""_exponent(long double value) noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include "xieite/math/literals/exponent.hpp"

int main() {
    using namespace xieite::math::literals::exponent;

    std::cout << (2 ** 5_exponent) << '\n';
}
```
Output:
```
32
```
