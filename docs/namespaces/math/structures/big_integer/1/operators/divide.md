# [xieite](../../../../../xieite.md)\:\:[math](../../../../../math.md)\:\:[BigInteger<Limb>](../../../../big_integer.md)\:\:operator/\<\>\(\)
Defined in fragment [xieite:math.BigInteger](../../../../../../../src/math/big_integer.cpp)

&nbsp;

## Description
Returns the quotient of two big-integers. Dividing by zero invokes undefined behavior.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] friend constexpr xieite::math::BigInteger<Limb> operator/(const xieite::math::BigInteger<Limb>& dividend, const xieite::math::BigInteger<Limb>& divisor);
```
#### 2)
```cpp
template<std::integral Integral>
[[nodiscard]] friend constexpr xieite::math::BigInteger<Limb> operator/(const xieite::math::BigInteger<Limb>& dividend, Integral divisor);
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", (xieite::math::BigInteger(9) / 3).string());
}
```
Output:
```
3
```
