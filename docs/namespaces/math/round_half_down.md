# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:roundHalfDown\<\>\(\)
Defined in fragment [xieite:math.roundHalfDown](../../../src/math/round_half_down.cpp)

&nbsp;

## Description
Rounds a value to the nearest multiple of a step [like so](https://en.wikipedia.org/wiki/Rounding#Rounding_half_down).

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Arithmetic Arithmetic>
[[nodiscard]] constexpr Arithmetic roundHalfDown(Arithmetic value, std::common_type_t<Arithmetic> step = 1) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", xieite::math::roundHalfDown(-5, 10));
}
```
Output:
```
-10
```
