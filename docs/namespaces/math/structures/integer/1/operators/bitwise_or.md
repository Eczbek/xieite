# [xieite](../../../../../xieite.md)\:\:[math](../../../../../math.md)\:\:[Integer<bits, sign>](../../../../integer.md)\:\:operator|\(\)
Defined in fragment [xieite:math.Integer](../../../../../../../src/math/integer.cpp)

&nbsp;

## Description
Returns the bitwise OR result of two integers.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] friend constexpr xieite::math::Integer<bits, sign> operator|(xieite::math::Integer<bits, sign> leftOperand, xieite::math::Integer<bits, sign> rightOperand) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", (xieite::math::Integer<4, false>(9) | 3).data());
}
```
Output:
```
11
```
