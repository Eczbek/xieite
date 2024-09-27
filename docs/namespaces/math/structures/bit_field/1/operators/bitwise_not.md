# [xieite](../../../../../xieite.md)\:\:[math](../../../../../math.md)\:\:[BitField<bits, sign>](../../../../bit_field.md)\:\:operator~\(\)
Defined in fragment [xieite:math.BitField](../../../../../../../src/math/bit_field.cpp)

&nbsp;

## Description
Returns the bitwise NOT result of this integer.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] constexpr BitField operator~() const noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", (~xieite::math::BitField<4, false>(3)).data());
}
```
Output:
```
12
```
