# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:limitsMagnitude\<\>\(\)
Defined in fragment [xieite:math.limitsMagnitude](../../../src/math/limits_magnitude.cpp)

&nbsp;

## Description
Returns the minimum and maximum of the magnitudes of multiple values, in order.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Arithmetic First, std::convertible_to<First>... Rest>
[[nodiscard]] constexpr xieite::math::Interval<First> limitsMagnitude(First first, Rest... rest) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    auto limits = xieite::math::limitsMagnitude(4, 999, 17, -5, 0);
    //                                             ^^^          ^
    std::println("{} {}", limits.start, limits.end);
}
```
Output:
```
0 999
```
