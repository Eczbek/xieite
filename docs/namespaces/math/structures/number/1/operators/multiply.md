# [xieite](../../../../../xieite.md)\:\:[math](../../../../../math.md)\:\:[Number<Arithmetic>](../../../../number.md)\:\:operator*\(\)
Defined in fragment [xieite:math.Number](../../../../../../../src/math/number.cpp)

&nbsp;

## Description
Returns the product of two numbers.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] friend constexpr Number operator*(Number multiplier, Number multiplicand) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", (xieite::math::Number<int>(9) * 3).value);
}
```
Output:
```
11
```
