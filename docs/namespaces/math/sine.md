# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:sine\<\>\(\)
Defined in fragment [xieite:math.sine](../../../src/math/sine.cpp)

&nbsp;

## Description
Computes the sine of an optionally inverse, hyperbolic, or reciprocal theta.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Arithmetic Arithmetic, xieite::concepts::Arithmetic Result = std::common_type_t<double, Arithmetic>>
[[nodiscard]] constexpr Result sine(Arithmetic theta, bool inverse, bool hyperbolic, bool reciprocal) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    using namespace xieite::literals::units;

    std::println("{}", xieite::math::sine(45_degrees, true, false, true));
}
```
Possible output:
```
1.1070039900646695
```
