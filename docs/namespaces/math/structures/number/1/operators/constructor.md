# [xieite](../../../../../xieite.md)\:\:[math](../../../../../math.md)\:\:[Number<Arithmetic>](../../../number.md)\:\:Number\(\)
Defined in fragment [xieite:math.Number](../../../../../../../src/math/number.cpp)

&nbsp;

## Description
Constructs a `xieite::math::Number<Arithmetic>`.

&nbsp;

## Synopsis
#### 1)
```cpp
explicit(false) constexpr Number(Arithmetic value = 0) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", xieite::math::Number<int>(418).value);
}
```
Output:
```
418
```
