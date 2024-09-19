# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:roundHalfUp\<\>\(\)
Defined in fragment [xieite:math.roundHalfUp](../../../src/math/round_half_up.cpp)

&nbsp;

## Description
Rounds a value to the nearest multiple of a step [like so](https://en.wikipedia.org/wiki/Rounding#Rounding_half_up).

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Arithmetic Arithmetic>
[[nodiscard]] constexpr Arithmetic roundHalfUp(Arithmetic value, std::type_identity_t<Arithmetic> step = 1) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", xieite::math::roundHalfUp(-5, 10));
}
```
Output:
```
0
```
