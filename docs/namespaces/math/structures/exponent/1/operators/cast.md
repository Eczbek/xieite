# [xieite](../../../../../../xieite.md)\:\:[math](../../../../../../math.md)\:\:[Exponent<Arithmetic>](../../../../exponent.md)\:\:operator typename\<\>\(\)
Defined in fragment [xieite:math.Exponent](../../../../../../../src/math/exponent.cpp)

&nbsp;

## Description
Casts a `xieite::math::Exponent` to its underlying type.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Arithmetic OtherArithmetic>
[[nodiscard]] explicit(false) constexpr operator std::common_type_t<Arithmetic, OtherArithmetic>() const noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    auto exponent = xieite::math::Exponent(5);

    std::println("{}", static_cast<int>(exponent));
}
```
Output:
```
5
```
