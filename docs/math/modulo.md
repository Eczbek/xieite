# [xieite](../xieite.md)\:\:[math](../math.md)\:\:modulo
Defined in header [<xieite/math/modulo.hpp>](../../include/xieite/math/modulo.hpp)

&nbsp;

## Synopses
#### 1)
```cpp
template<xieite::concepts::Arithmetic Arithmetic>
[[nodiscard]] constexpr Arithmetic modulo(Arithmetic dividend, Arithmetic divisor) noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/math/modulo.hpp>

int main() {
    std::cout << xieite::math::modulo(-21, 4) << '\n';
}
```
Output:
```
3
```
