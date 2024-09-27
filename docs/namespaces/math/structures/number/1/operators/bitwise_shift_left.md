# [xieite](../../../../../xieite.md)\:\:[math](../../../../../math.md)\:\:[Number<Arithmetic>](../../../../number.md)\:\:operator\<\<\(\)
Defined in fragment [xieite:math.Number](../../../../../../../src/math/number.cpp)

&nbsp;

## Description
Returns this number bitwise shifted to the left.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] friend constexpr Number operator<<(Number leftOperand, Number rightOperand) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", (xieite::math::Number<double>(9.625) << 3).value);
}
```
Output:
```
77
```
