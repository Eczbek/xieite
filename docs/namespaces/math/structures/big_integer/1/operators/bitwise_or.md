# [xieite](../../../../../xieite.md)\:\:[math](../../../../../math.md)\:\:[BigInteger<Limb>](../../../../big_integer.md)\:\:operator|\<\>\(\)
Defined in fragment [xieite:math.BigInteger](../../../../../../../src/math/big_integer.cpp)

&nbsp;

## Description
Returns the bitwise OR result of two big-integers.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] friend constexpr xieite::math::BigInteger<Limb> operator|(const xieite::math::BigInteger<Limb>& leftOperand, const xieite::math::BigInteger<Limb>& rightOperand) noexcept;
```
#### 2)
```cpp
template<std::integral Integral>
[[nodiscard]] friend constexpr xieite::math::BigInteger<Limb> operator|(const xieite::math::BigInteger<Limb>& leftOperand, Integral rightOperand) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", (xieite::math::BigInteger(9) | 3).string());
}
```
Output:
```
11
```
