# [xieite](../../../../../xieite.md)\:\:[math](../../../../../math.md)\:\:[Number<Arithmetic>](../../../../number.md)\:\:operator\>\>=\(\)
Defined in fragment [xieite:math.Number](../../../../../../../src/math/number.cpp)

&nbsp;

## Description
Assigns this number to itself bitwise shifted to the right.

&nbsp;

## Synopsis
#### 1)
```cpp
constexpr Number& operator>>=(Number positions) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    xieite::math::Number<4, false> number = 9.625;

    number >>= 3;

    std::println("{}", number.value);
}
```
Output:
```
1.203125
```
