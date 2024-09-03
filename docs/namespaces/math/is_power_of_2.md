# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:isPowerOf2\<\>\(\)
Defined in fragment [xieite:math.isPowerOf2](../../../src/math/is_power_of_2.cpp)

&nbsp;

## Description
Checks that a value is a power of 2.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::unsigned_integral UnsignedIntegral>
[[nodiscard]] constexpr bool isPowerOf2(UnsignedIntegral value) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", xieite::math::isPowerOf2<unsigned int>(4));
    std::println("{}", xieite::math::isPowerOf2<unsigned int>(0));
}
```
Output:
```
true
false
```
