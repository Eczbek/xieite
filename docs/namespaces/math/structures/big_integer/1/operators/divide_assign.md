# [xieite](../../../../../xieite.md)\:\:[math](../../../../../math.md)\:\:[BigInteger<Limb>](../../../../big_integer.md)\:\:operator/=\<\>\(\)
Defined in fragment [xieite:math.BigInteger](../../../../../../../src/math/big_integer.cpp)

&nbsp;

## Description
Assigns the quotient of this big-integer with another. Dividing by zero throws `std::out_of_range`.

&nbsp;

## Synopsis
#### 1)
```cpp
constexpr xieite::math::BigInteger<Limb>& operator/=(const xieite::math::BigInteger<Limb>& divisor);
```
#### 2)
```cpp
template<std::integral Integral>
constexpr xieite::math::BigInteger<Limb>& operator/=(Integral divisor);
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    xieite::math::BigInteger bigIntegral = 9;

    bigIntegral /= 3;

    std::println("{}", bigIntegral.string());
}
```
Output:
```
3
```
