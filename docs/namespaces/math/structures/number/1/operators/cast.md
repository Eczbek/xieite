# [xieite](../../../../../xieite.md)\:\:[math](../../../../../math.md)\:\:[Number<Arithmetic>](../../../../number.md)\:\:operator typename\<\>\(\)
Defined in fragment [xieite:math.Number](../../../../../../../src/math/number.cpp)

&nbsp;

## Description
Casts a number to its underlying type or to another number wrapper type.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] explicit constexpr operator Arithmetic() const noexcept;
```
#### 2)
```cpp
template<xieite::concepts::Arithmetic OtherArithmetic>
[[nodiscard]] explicit constexpr operator xieite::math::Number<Arithmetic>() const noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", static_cast<xieite::math::Number<int>>(xieite::math::Number<double>(9.625)).data());
}
```
Output:
```
9
```
