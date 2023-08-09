# [xieite](../xieite.md)\:\:[math](../math.md)\:\:farthestFrom
Defined in header [<xieite/math/farthestFrom.hpp>](../../include/xieite/math/farthestFrom.hpp)

&nbsp;

## Description
Selects the value farthest from a target.

&nbsp;

## Synopses
#### 1)
```cpp
template<xieite::concepts::Arithmetic Arithmetic1, xieite::concepts::Arithmetic Arithmetic2, xieite::concepts::Arithmetic Arithmetic3>
constexpr xieite::math::Result<Arithmetic1, Arithmetic2, Arithmetic3>& farthestFrom(Arithmetic1 target, Arithmetic2& value1, Arithmetic3& value2) noexcept;
```
#### 2)
```cpp
template<xieite::concepts::Arithmetic Arithmetic1, xieite::concepts::Arithmetic Arithmetic2, xieite::concepts::Arithmetic3>
constexpr const xieite::math::Result<Arithmetic1, Arithmetic2, Arithmetic3>& farthestFrom(Arithmetic1 target, const Arithmetic2& value1, const Arithmetic3& value2) noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/math/farthestFrom.hpp>

int main() {
    std::cout << xieite::math::farthestFrom(0, 5, -1) << '\n';
}
```
Output:
```
5
```
