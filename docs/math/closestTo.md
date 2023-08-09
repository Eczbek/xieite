# [xieite](../xieite.md)\:\:[math](../math.md)\:\:closestTo
Defined in header [<xieite/math/closestTo.hpp>](../../include/xieite/math/closestTo.hpp)

&nbsp;

## Description
Selects the value closest to a target.

&nbsp;

## Synopses
#### 1)
```cpp
template<xieite::concepts::Arithmetic Arithmetic1, xieite::concepts::Arithmetic Arithmetic2, xieite::concepts::Arithmetic Arithmetic3>
[[nodiscard]]
constexpr xieite::math::Result<Arithmetic1, Arithmetic2, Arithmetic3>& closestTo(Arithmetic1 target, Arithmetic2& value1, Arithmetic3& value2) noexcept;
```
#### 2)
```cpp
template<xieite::concepts::Arithmetic Arithmetic1, xieite::concepts::Arithmetic Arithmetic2, xieite::concepts::Arithmetic Arithmetic3>
[[nodiscard]]
constexpr const xieite::math::Result<Arithmetic1, Arithmetic2, Arithmetic3>& closestTo(Arithmetic1 target, const Arithmetic2& value1, const Arithmetic3& value2) noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/math/closestTo.hpp>

int main() {
    std::cout << xieite::math::closestTo(0, 5, -1) << '\n';
}
```
Output:
```
-1
```
