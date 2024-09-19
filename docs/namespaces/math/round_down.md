# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:roundDown\<\>\(\)
Defined in fragment [xieite:math.roundDown](../../../src/math/round_down.cpp)

&nbsp;

## Description
Rounds a value to the nearest multiple of a step downwards.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Arithmetic Arithmetic>
[[nodiscard]] constexpr Arithmetic roundDown(Arithmetic value, std::type_identity_t<Arithmetic> step = 1) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", xieite::math::roundDown(-21, 5));
}
```
Output:
```
-25
```
