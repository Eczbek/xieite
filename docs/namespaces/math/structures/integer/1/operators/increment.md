# [xieite](../../../../../xieite.md)\:\:[math](../../../../../math.md)\:\:[Integer<bits, sign>](../../../../integer.md)\:\:operator++\(\)
Defined in fragment [xieite:math.Integer](../../../../../../../src/math/integer.cpp)

&nbsp;

## Description
Increments a integer.

&nbsp;

## Synopsis
#### 1)
```cpp
constexpr xieite::math::Integer<bits, sign>& operator++() noexcept;
```
#### 2)
```cpp
constexpr xieite::math::Integer<bits, sign>& operator++(int) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    xieite::math::Integer<4, false> integer = 7;

    std::println("{}", (++integer).data());
}
```
Output:
```
8
```
