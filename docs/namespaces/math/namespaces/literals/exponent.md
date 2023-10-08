# [xieite](../../../../xieite.md)\:\:[math](../../../../math.md)\:\:[literals](../literals.md)\:\:\_exponent
Defined in header [<xieite/math/literals/exponent.hpp>](../../../../../include/xieite/math/literals/exponent.hpp)

&nbsp;

## Synopses
#### 1)
```cpp
[[nodiscard]] constexpr auto operator""_exponent(const unsigned long long int value) noexcept;
```
#### 2)
```cpp
[[nodiscard]] constexpr auto operator""_exponent(const long double value) noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/math/literals/exponent.hpp>

int main() {
    using namespace xieite::math::literals;

    std::cout << (2 ** 5_exponent) << '\n';
}
```
Output:
```
32
```
