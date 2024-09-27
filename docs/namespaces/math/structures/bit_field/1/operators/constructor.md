# [xieite](../../../../../xieite.md)\:\:[math](../../../../../math.md)\:\:[BitField<bits, sign>](../../../bit_field.md)\:\:BitField\<\>\(\)
Defined in fragment [xieite:math.BitField](../../../../../../../src/math/bit_field.cpp)

&nbsp;

## Description
Constructs a `xieite::math::BitField<bits, sign>`.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::integral OtherIntegral = int>
constexpr BitField(OtherIntegral value = 0) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", xieite::math::BitField<6, false>(418).data());
}
```
Output:
```
34
```
