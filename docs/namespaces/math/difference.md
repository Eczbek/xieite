# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:difference\<\>\(\)
Defined in fragment [xieite:math.difference](../../../src/math/difference.cpp)

&nbsp;

## Description
Computes the absolute difference between two values. Handles some edge cases.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Arithmetic Arithmetic>
[[nodiscard]] constexpr xieite::types::TryUnsigned<Arithmetic> difference(Arithmetic value1, Arithmetic value2) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::int8_t min = std::numeric_limits<std::int8_t>::min();
    std::int8_t max = std::numeric_limits<std::int8_t>::max();

    std::println("{}", min);
    std::println("{}", max);
    std::println("{}", xieite::math::difference(min, max));
}
```
Output:
```
-128
127
255
```
