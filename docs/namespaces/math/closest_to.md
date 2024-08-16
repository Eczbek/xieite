# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:closestTo\<\>\(\)
Defined in header [<xieite/math/closest_to.hpp>](../../../include/xieite/math/closest_to.hpp)

&nbsp;

## Description
Selects the value closest to a target.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Arithmetic Arithmetic>
[[nodiscard]] constexpr Arithmetic& closestTo(Arithmetic target, Arithmetic& value1, Arithmetic& value2) noexcept;
```
#### 2)
```cpp
template<xieite::concepts::Arithmetic Arithmetic>
[[nodiscard]] constexpr Arithmetic closestTo(Arithmetic target, const Arithmetic& value1, const Arithmetic& value2) noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/math/closest_to.hpp"

int main() {
    std::println("{}", xieite::math::closestTo(0, 5, -1));
}
```
Output:
```
-1
```
