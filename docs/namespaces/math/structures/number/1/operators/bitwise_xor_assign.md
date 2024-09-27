# [xieite](../../../../../xieite.md)\:\:[math](../../../../../math.md)\:\:[Number<Arithmetic>](../../../../number.md)\:\:operator^=\(\)
Defined in fragment [xieite:math.Number](../../../../../../../src/math/number.cpp)

&nbsp;

## Description
Assigns the bitwise XOR result of this number with another.

&nbsp;

## Synopsis
#### 1)
```cpp
constexpr Number& operator^=(Number operand) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    xieite::math::Number<double> number = 9.625;

    number ^= 3.25;

    std::println("{}", number.value);
}
```
Output:
```
10.875
```
