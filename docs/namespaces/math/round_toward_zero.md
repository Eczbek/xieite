# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:roundTowardZero\<\>\(\)
Defined in fragment [xieite:math.roundTowardZero](../../../src/math/round_toward_zero.cpp)

&nbsp;

## Description
Rounds a value to the nearest multiple of a step toward zero.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Arithmetic Arithmetic>
[[nodiscard]] constexpr Arithmetic roundTowardZero(Arithmetic value, std::type_identity_t<Arithmetic> step = 1) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", xieite::math::roundTowardZero(24, 5));
}
```
Output:
```
20
```
