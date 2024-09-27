# [xieite](../../../../../xieite.md)\:\:[math](../../../../../math.md)\:\:[BitField<bits, sign>](../../../../bit_field.md)\:\:operator typename\<\>\(\)
Defined in fragment [xieite:math.BitField](../../../../../../../src/math/bit_field.cpp)

&nbsp;

## Description
Casts this wrapper to another type.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::integral Integral>
[[nodiscard]] explicit constexpr operator Integral() const noexcept;
```
#### 2)
```cpp
template<std::size_t otherBits, bool otherSign>
[[nodiscard]] explicit constexpr operator xieite::math::BitField<otherBits, otherSign>() const noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", static_cast<xieite::math::BitField<3, false>>(xieite::math::BitField<4, false>(9)).data());
}
```
Output:
```
1
```
