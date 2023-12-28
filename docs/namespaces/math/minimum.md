# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:minimum
Defined in header [<xieite/math/minimum.hpp>](../../../include/xieite/math/minimum.hpp)

&nbsp;

## Description
Computes the minimum of some values. Returns `0` if no arguments are passed.

&nbsp;

## Synopses
#### 1)
```cpp
template<xieite::concepts::Arithmetic... Numbers>
[[nodiscard]] constexpr xieite::math::Result<Numbers...> minimum(const Numbers... values) noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/math/minimum.hpp>

int main() {
    std::cout << xieite::math::minimum(1, 3, 2, 4, 5) << '\n';
}
```
Output:
```
1
```
