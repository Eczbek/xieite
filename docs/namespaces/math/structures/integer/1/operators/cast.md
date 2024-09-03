# [xieite](../../../../../xieite.md)\:\:[math](../../../../../math.md)\:\:[Integer<bits, sign>](../../../../integer.md)\:\:operator typename\(\)
Defined in fragment [xieite:math.Integer](../../../../../../../src/math/integer.cpp)

&nbsp;

## Description
Casts a `xieite::math::Integer<bits, sign>` to another integer type.

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
[[nodiscard]] explicit constexpr operator xieite::math::Integer<otherBits, otherSign>() const noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", static_cast<xieite::math::Integer<3, false>>(xieite::math::Integer<4, false>(9)).data());
}
```
Output:
```
1
```
