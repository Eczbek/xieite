# [xieite](../../../../../xieite.md)\:\:[math](../../../../../math.md)\:\:[Number<Arithmetic>](../../../../number.md)\:\:operator\<=\>\(\)
Defined in fragment [xieite:math.Number](../../../../../../../src/math/number.cpp)

&nbsp;

## Description
Compares two numbers.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] friend constexpr std::strong_ordering operator<=>(Number leftComparand, Number rightComparand) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", xieite::math::Number<int>(9) > 3);
}
```
Output:
```
true
```
