# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:roundTowardInfinity\<\>\(\)
Defined in fragment [xieite:math.roundTowardInfinity](../../../src/math/round_toward_infinity.cpp)

&nbsp;

## Description
Rounds a value to the nearest multiple of a step toward infinity.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Arithmetic Arithmetic>
[[nodiscard]] constexpr Arithmetic roundTowardInfinity(Arithmetic value, std::common_type_t<Arithmetic> step = 1) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", xieite::math::roundTowardInfinity(21, 5));
}
```
Output:
```
25
```
