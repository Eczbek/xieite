# [xieite](../xieite.md)\:\:[math](../math.md)\:\:wrap
Defined in header [<xieite/math/wrap.hpp>](../../include/xieite/math/wrap.hpp)

&nbsp;

## Description
"Wraps" a number between two limits, inclusively.

&nbsp;

## Synopses
#### 1)
```cpp
template<xieite::concepts::Numeric Number1, xieite::concepts::Numeric Number2, xieite::concepts::Numeric Number3>
constexpr std::common_type_t<Number1, Number2, Number3> wrap(Number1 value, Number2 limit1, Number3 limit2) noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/math/wrap.hpp>

int main() {
    std::cout << xieite::math::wrap(23, 4, -2) << '\n';
}
```
Output:
```
-1
```
