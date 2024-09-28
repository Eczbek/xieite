# [xieite](../../../../../xieite.md)\:\:[math](../../../../../math.md)\:\:[BitField<bits, sign>](../../../../bit_field.md)\:\:operator\>\>\(\)
Defined in fragment [xieite:math.BitField](../../../../../../../src/math/bit_field.cpp)

&nbsp;

## Description
Returns this integer bitwise shifted to the right.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] friend constexpr BitField operator>>(BitField leftOperand, BitField rightOperand) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", (xieite::math::BitField<4, false>(9) >> 3).data());
}
```
Output:
```
1
```