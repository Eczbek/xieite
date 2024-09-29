# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:average\<\>\(\)
Defined in fragment [xieite:math.average](../../../src/math/average.cpp)

&nbsp;

## Description
Computes the average of several integers, safely.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::integral First, std::convertible_to<First>... Rest>
[[nodiscard]] constexpr First average(First first, Rest... rest) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", xieite::math::average(12, 53, -97, 929, 4));
}
```
Output:
```
180
```
