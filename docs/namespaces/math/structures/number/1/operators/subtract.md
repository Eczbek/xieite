# [xieite](../../../../../xieite.md)\:\:[math](../../../../../math.md)\:\:[Number<Arithmetic>](../../../../number.md)\:\:operator-\(\)
Defined in fragment [xieite:math.Number](../../../../../../../src/math/number.cpp)

&nbsp;

## Description
Returns the difference between two numbers.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] constexpr Number operator-() const noexcept;
```
#### 2)
```cpp
[[nodiscard]] friend constexpr Number operator-(Number minuend, Number subtrahend) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", (xieite::math::Number<int>(9) - 3).value);
}
```
Output:
```
6
```
