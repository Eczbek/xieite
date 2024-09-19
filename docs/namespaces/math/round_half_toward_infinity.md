# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:roundHalfTowardInfinity\<\>\(\)
Defined in fragment [xieite:math.roundHalfTowardInfinity](../../../src/math/round_half_toward_infinity.cpp)

&nbsp;

## Description
Rounds a value to the nearest multiple of a step [like so](https://en.wikipedia.org/wiki/Rounding#Rounding_half_away_from_zero).

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Arithmetic Arithmetic>
[[nodiscard]] constexpr Arithmetic roundHalfTowardInfinity(Arithmetic value, std::type_identity_t<Arithmetic> step = 1) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", xieite::math::roundHalfTowardInfinity(5, 10));
}
```
Output:
```
10
```
