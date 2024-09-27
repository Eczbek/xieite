# [xieite](../../../../../xieite.md)\:\:[math](../../../../../math.md)\:\:[Number<Arithmetic>](../../../../number.md)\:\:operator&\(\)
Defined in fragment [xieite:math.Number](../../../../../../../src/math/number.cpp)

&nbsp;

## Description
Returns the bitwise AND result of two numbers.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] friend constexpr Number operator&(Number leftOperand, Number rightOperand) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", (xieite::math::Number<double>(9.25) & 3.25).value);
}
```
Output:
```
1.25
```
