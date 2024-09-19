# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:closestTo\<\>\(\)
Defined in fragment [xieite:math.closestTo](../../../src/math/closest_to.cpp)

&nbsp;

## Description
Selects the value closest to a target.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Arithmetic Arithmetic>
[[nodiscard]] constexpr Arithmetic& closestTo(Arithmetic target, std::type_identity_t<Arithmetic>& value1, std::type_identity_t<Arithmetic>& value2) noexcept;
```
#### 2)
```cpp
template<xieite::concepts::Arithmetic Arithmetic>
[[nodiscard]] constexpr Arithmetic closestTo(Arithmetic target, const std::type_identity_t<Arithmetic>& value1, const std::type_identity_t<Arithmetic>& value2) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", xieite::math::closestTo(0, 5, -1));
}
```
Output:
```
-1
```
