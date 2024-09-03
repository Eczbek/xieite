# [xieite](../../../../../xieite.md)\:\:[math](../../../../../math.md)\:\:[Integer<bits, sign>](../../../../integer.md)\:\:operator==\(\)
Defined in fragment [xieite:math.Integer](../../../../../../../src/math/integer.cpp)

&nbsp;

## Description
Compares two integers.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] friend constexpr bool operator==(xieite::math::Integer<bits, sign> leftComparand, xieite::math::Integer<bits, sign> rightComparand) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", xieite::math::Integer<4, false>(16) == 0);
}
```
Output:
```
true
```
