# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:logarithm\<\>\(\)
Defined in fragment [xieite:math.logarithm](../../../src/math/logarithm.cpp)

&nbsp;

## Description
Takes the logarithm of a value in any base.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Arithmetic Arithmetic, xieite::concepts::Arithmetic Result = std::common_type_t<double, Arithmetic>>
[[nodiscard]] constexpr Result logarithm(Arithmetic base, std::common_type_t<Arithmetic> value) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", xieite::math::logarithm(5, 170));
}
```
Possible output:
```
3.1910509857959815
```
