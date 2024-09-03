# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:power\<\>\(\)
Defined in fragment [xieite:math.power](../../../src/math/power.cpp)

&nbsp;

## Description
Computes a power of an integer.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::integral Integral>
[[nodiscard]] constexpr Integral power(Integral base, std::size_t exponent) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", xieite::math::power<std::uint64_t>(4, 13));
}
```
Output:
```
67108864
```
