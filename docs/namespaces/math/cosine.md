# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:cosine\<\>\(\)
Defined in fragment [xieite:math.cosine](../../../src/math/cosine.cpp)

&nbsp;

## Description
Computes the cosine of an optionally inverse, hyperbolic, or reciprocal theta.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Arithmetic Arithmetic, xieite::concepts::Arithmetic Result = std::common_type_t<double, Arithmetic>>
[[nodiscard]] constexpr Result cosine(Arithmetic theta, bool inverse, bool hyperbolic, bool reciprocal) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    using namespace xieite::literals::units;

    std::println("{}", xieite::math::cosine(45_degrees, false, true, false));
}
```
Possible output:
```
1.3246090892520057
```
