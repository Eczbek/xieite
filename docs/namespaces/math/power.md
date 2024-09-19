# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:power\<\>\(\)
Defined in fragment [xieite:math.power](../../../src/math/power.cpp)

&nbsp;

## Description
A wrapper for `std::pow()` and a specialization for integer types. For integers, raising zero to a negative exponent throws `std::out_of_range`.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Arithmetic Arithmetic>
[[nodiscard]] constexpr Arithmetic power(Arithmetic base, std::type_identity_t<Arithmetic> exponent) noexcept;
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
