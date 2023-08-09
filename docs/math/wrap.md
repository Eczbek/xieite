# [xieite](../xieite.md)\:\:[math](../math.md)\:\:wrap
Defined in header [<xieite/math/wrap.hpp>](../../include/xieite/math/wrap.hpp)

&nbsp;

## Description
"Wraps" a number between two limits, inclusively.

&nbsp;

## Synopses
#### 1)
```cpp
template<xieite::concepts::Arithmetic Arithmetic1, xieite::concepts::Arithmetic Arithmetic2, xieite::concepts::Arithmetic Arithmetic3>
constexpr std::common_type_t<Arithmetic1, Arithmetic2, Arithmetic3> wrap(Arithmetic1 value, Arithmetic2 limit1, Arithmetic3 limit2) noexcept;
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
