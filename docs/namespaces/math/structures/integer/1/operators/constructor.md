# [xieite](../../../../../xieite.md)\:\:[math](../../../../../math.md)\:\:[Integer<bits, sign>](../../../integer.md)\:\:Integral\(\)
Defined in fragment [xieite:math.Integer](../../../../../../../src/math/integer.cpp)

&nbsp;

## Description
Constructs a `xieite::math::Integer<bits, sign>`.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::integral OtherIntegral = int>
constexpr Integral(OtherIntegral value = 0) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", xieite::math::Integer<6, false>(418).data());
}
```
Output:
```
34
```
