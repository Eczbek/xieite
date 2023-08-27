# [xieite](../xieite.md)\:\:[math](../math.md)\:\:wrap
Defined in header [<xieite/math/wrap.hpp>](../../include/xieite/math/wrap.hpp)

&nbsp;

## Description
"Wraps" a number between two limits, inclusively.

&nbsp;

## Synopses
#### 1)
```cpp
template<xieite::concepts::Numeric Number>
constexpr Number wrap(const Number value, const Number limit1, const Number limit2) noexcept;
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
