# [xieite](../../../../../xieite.md)\:\:[math](../../../../../math.md)\:\:[BigInteger<Limb>](../../../big_integer.md)\:\:logarithm\<\>\(\)
Defined in fragment [xieite:math.BigInteger](../../../../../../src/math/big_integer.cpp)

&nbsp;

## Description
Computes the logarithm of a `xieite::math::BigInteger<Limb>` to a base. Taking the logarithm of a negative value, to a unary base, or to a negative base throws `std::out_of_range`.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] constexpr xieite::math::BigInteger<Limb> logarithm(const xieite::math::BigInteger<Limb>& base) const;
```
#### 2)
```cpp
template<std::integral Integral>
[[nodiscard]] constexpr xieite::math::BigInteger<Limb> logarithm(Integral base) const;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    xieite::math::BigInteger bigIntegral = 1000;

    std::println("{}", bigIntegral.logarithm(10).string());
}
```
Output:
```
3
```
