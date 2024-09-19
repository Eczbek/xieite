# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:roundUp\<\>\(\)
Defined in fragment [xieite:math.roundUp](../../../src/math/round_up.cpp)

&nbsp;

## Description
Rounds a value to the nearest multiple of a step upwards.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Arithmetic Arithmetic>
[[nodiscard]] constexpr Arithmetic roundUp(Arithmetic value, std::type_identity_t<Arithmetic> step = 1) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", xieite::math::roundUp(-24, 5));
}
```
Output:
```
-20
```
