# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:remainder\<\>\(\)
Defined in fragment [xieite:math.remainder](../../../src/math/remainder.cpp)

&nbsp;

## Description
Computes the remainder after division.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Arithmetic Arithmetic>
[[nodiscard]] constexpr Arithmetic remainder(Arithmetic dividend, std::common_type_t<Arithmetic> divisor) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", xieite::math::remainder(-21, 4));
}
```
Output:
```
-1
```
