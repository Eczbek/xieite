# [xieite](../../../../../xieite.md)\:\:[math](../../../../../math.md)\:\:[BitField<bits, sign>](../../../../bit_field.md)\:\:operator*\(\)
Defined in fragment [xieite:math.BitField](../../../../../../../src/math/bit_field.cpp)

&nbsp;

## Description
Returns the product of two integers.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] friend constexpr BitField operator*(BitField multiplier, BitField multiplicand) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", (xieite::math::BitField<4, false>(9) * 3).data());
}
```
Output:
```
11
```
