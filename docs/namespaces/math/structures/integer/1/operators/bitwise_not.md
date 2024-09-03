# [xieite](../../../../../xieite.md)\:\:[math](../../../../../math.md)\:\:[Integer<bits, sign>](../../../../integer.md)\:\:operator~\(\)
Defined in fragment [xieite:math.Integer](../../../../../../../src/math/integer.cpp)

&nbsp;

## Description
Returns the bitwise NOT result of this integer.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] constexpr xieite::math::Integer<bits, sign> operator~() const noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", (~xieite::math::Integer<4, false>(3)).data());
}
```
Output:
```
12
```
