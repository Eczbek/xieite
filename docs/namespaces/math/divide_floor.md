# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:divideFloor\(\)
Defined in header [<xieite/math/divide_floor.hpp>](../../../include/xieite/math/divide_floor.hpp)

&nbsp;

## Description
Computes the floor value of a division.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::integral Integer>
[[nodiscard]] constexpr Integer divideFloor(Integer dividend, Integer divisor) noexcept;
```
#### 2)
```cpp
template<std::floating_point FloatingPoint>
[[nodiscard]] constexpr FloatingPoint divideFloor(FloatingPoint dividend, FloatingPoint divisor) noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/math/divide_floor.hpp"

int main() {
    std::println("{}", xieite::math::divideFloor(249, 16));
}
```
Output:
```
15
```
