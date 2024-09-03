# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:isNegative\<\>\(\)
Defined in fragment [xieite:math.isNegative](../../../src/math/is_negative.cpp)

&nbsp;

## Description
Checks that a value is negative.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Arithmetic Arithmetic>
[[nodiscard]] constexpr bool isNegative(Arithmetic value) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", xieite::math::isNegative(4));
    std::println("{}", xieite::math::isNegative(-23));
}
```
Output:
```
false
true
```
