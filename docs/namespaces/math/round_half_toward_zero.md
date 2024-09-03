# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:roundHalfTowardZero\<\>\(\)
Defined in fragment [xieite:math.roundHalfTowardZero](../../../src/math/round_half_toward_zero.cpp)

&nbsp;

## Description
Rounds a value to the nearest multiple of a step [like so](https://en.wikipedia.org/wiki/Rounding#Rounding_half_toward_zero).

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Arithmetic Arithmetic>
[[nodiscard]] constexpr Arithmetic roundHalfTowardZero(Arithmetic value, Arithmetic step = 1) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", xieite::math::roundHalfTowardZero(5, 10));
}
```
Output:
```
0
```
