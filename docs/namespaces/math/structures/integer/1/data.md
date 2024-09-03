# [xieite](../../../../../xieite.md)\:\:[math](../../../../../math.md)\:\:[Integer<bits, sign>](../../../integer.md)\:\:data\(\)
Defined in fragment [xieite:math.Integer](../../../../../../src/math/integer.cpp)

&nbsp;

## Description
Returns the underlying integer value.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] constexpr xieite::math::Integer<bits, sign>::Limb data() const noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    xieite::math::Integer<3, false> integer = 14;

    std::println("{}", integer.data());
}
```
Output:
```
6
```
