# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:limitsFixed\<\>\(\)
Defined in fragment [xieite:math.limitsFixed](../../../src/math/limits_fixed.cpp)

&nbsp;

## Description
Returns the minimum and maximum of multiple values, in order.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::math::Arithmetic First, std::convertible_to<First>... Rest>
[[nodiscard]] constexpr xieite::math::Interval<First> limitsFixed(First first, Rest... rest) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    auto limits = xieite::math::limitsFixed(4, 999, 17, -5, 0);
    //                                         ^^^      ^^
    std::println("{} {}", limits.start, limits.end);
}
```
Output:
```
-5 999
```
