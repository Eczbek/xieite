# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:factorial
Defined in header [<xieite/math/factorial.hpp>](../../../include/xieite/math/factorial.hpp)

&nbsp;

## Description
Calculates the factorial of a value.

&nbsp;

## Synopses
#### 1)
```cpp
[[nodiscard]] constexpr std::size_t factorial(std::size_t value) noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/math/factorial.hpp>

int main() {
    std::cout << xieite::math::factorial(17) << '\n';
}
```
Output:
```
355687428096000
```
