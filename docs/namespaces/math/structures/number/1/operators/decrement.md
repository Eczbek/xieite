# [xieite](../../../../../xieite.md)\:\:[math](../../../../../math.md)\:\:[Number<Arithmetic>](../../../../number.md)\:\:operator--\(\)
Defined in fragment [xieite:math.Number](../../../../../../../src/math/number.cpp)

&nbsp;

## Description
Decrements a number.

&nbsp;

## Synopsis
#### 1)
```cpp
constexpr Number& operator--() noexcept;
```
#### 2)
```cpp
constexpr Number& operator--(int) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    xieite::math::Number<int> number = 7;

    std::println("{}", (--number).value);
}
```
Output:
```
6
```
