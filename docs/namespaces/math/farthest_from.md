# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:farthestFrom\<\>\(\)
Defined in fragment [xieite:math.farthestFrom](../../../src/math/farthest_from.cpp)

&nbsp;

## Description
Selects the value farthest from a target.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Arithmetic Arithmetic>
[[nodiscard]] constexpr Arithmetic farthestFrom(Arithmetic target, std::type_identity_t<Arithmetic> value1, std::type_identity_t<Arithmetic> value2) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", xieite::math::farthestFrom(0, 5, -1));
}
```
Output:
```
5
```
