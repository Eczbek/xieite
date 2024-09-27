# [xieite](../../../../../xieite.md)\:\:[math](../../../../../math.md)\:\:[Number<Arithmetic>](../../../../number.md)\:\:operator/=\(\)
Defined in fragment [xieite:math.Number](../../../../../../../src/math/number.cpp)

&nbsp;

## Description
Assigns the quotient of this number with another.

&nbsp;

## Synopsis
#### 1)
```cpp
constexpr Number& operator/=(Number divisor);
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    xieite::math::Number<int> number = 9;

    number /= 3;

    std::println("{}", number.value);
}
```
Output:
```
3
```
