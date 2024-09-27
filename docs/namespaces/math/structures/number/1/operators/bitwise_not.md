# [xieite](../../../../../xieite.md)\:\:[math](../../../../../math.md)\:\:[Number<Arithmetic>](../../../../number.md)\:\:operator~\(\)
Defined in fragment [xieite:math.Number](../../../../../../../src/math/number.cpp)

&nbsp;

## Description
Returns the bitwise NOT result of this number.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] constexpr Number operator~() const noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", (~xieite::math::Number<double>(9.25)).value);
}
```
Output:
```
-10.25
```
