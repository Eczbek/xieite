# [xieite](../../../../../xieite.md)\:\:[math](../../../../../math.md)\:\:[Integer<bits, sign>](../../../../integer.md)\:\:operator%=\(\)
Defined in fragment [xieite:math.Integer](../../../../../../../src/math/integer.cpp)

&nbsp;

## Description
Assigns the remainder after division of this integer with another.

&nbsp;

## Synopsis
#### 1)
```cpp
constexpr xieite::math::Integer<bits, sign>& operator%=(xieite::math::Integer<bits, sign> divisor) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    xieite::math::Integer<4, false> integer = 9;

    integer %= 3;

    std::println("{}", integer.data());
}
```
Output:
```
0
```
