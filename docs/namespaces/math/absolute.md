# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:absolute\<\>\(\)
Defined in fragment [xieite:math.absolute](../../../src/math/absolute.cpp)

&nbsp;

## Description
Returns the unsigned absolute of a value.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::integral Integral>
[[nodiscard]] constexpr xieite::types::TryUnsigned<Integral> absolute(Integral value) noexcept;
```
#### 2)
```cpp
template<std::floating_point Fractional>
[[nodiscard]] constexpr Fractional absolute(Fractional value) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::int64_t value = std::numeric_limits<std::int64_t>::min();

    std::println("{}", value);
    std::println("{}", xieite::math::absolute(value));
}
```
Output:
```
-9223372036854775808
9223372036854775808
```
