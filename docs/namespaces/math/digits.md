# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:digits\<\>\(\)
Defined in fragment [xieite:math.digits](../../../src/math/digits.cpp)

&nbsp;

## Description
Computes the number of integral digits in a value of any radix.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::integral Integral>
[[nodiscard]] constexpr std::size_t digits(Integral value, std::common_type_t<Integral> radix = 10) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", xieite::math::digits(12));
    std::println("{}", xieite::math::digits(0b110110, 2));
}
```
Output:
```
2
6
```
