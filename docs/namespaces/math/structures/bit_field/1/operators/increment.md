# [xieite](../../../../../xieite.md)\:\:[math](../../../../../math.md)\:\:[BitField<bits, sign>](../../../../bit_field.md)\:\:operator++\(\)
Defined in fragment [xieite:math.BitField](../../../../../../../src/math/bit_field.cpp)

&nbsp;

## Description
Increments a integer.

&nbsp;

## Synopsis
#### 1)
```cpp
constexpr BitField& operator++() noexcept;
```
#### 2)
```cpp
constexpr BitField& operator++(int) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    xieite::math::BitField<4, false> integer = 7;

    std::println("{}", (++integer).data());
}
```
Output:
```
8
```
