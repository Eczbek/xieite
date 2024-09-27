# [xieite](../../../../../xieite.md)\:\:[math](../../../../../math.md)\:\:[BitField<bits, sign>](../../../../bit_field.md)\:\:operator-=\(\)
Defined in fragment [xieite:math.BitField](../../../../../../../src/math/bit_field.cpp)

&nbsp;

## Description
Assigns the difference between this integer and another.

&nbsp;

## Synopsis
#### 1)
```cpp
constexpr BitField& operator-=(BitField subtrahend) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    xieite::math::BitField<4, false> integer = 9;

    integer -= 3;

    std::println("{}", integer.data());
}
```
Output:
```
6
```
