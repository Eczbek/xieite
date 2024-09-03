# [xieite](../../../../../xieite.md)\:\:[math](../../../../../math.md)\:\:[BigInteger<Limb>](../../../big_integer.md)\:\:power\<\>\(\)
Defined in fragment [xieite:math.BigInteger](../../../../../../src/math/big_integer.cpp)

&nbsp;

## Description
Raises a `xieite::math::BigInteger<Limb>` to an exponent. Raising zero to a negative exponent invokes undefined behavior.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] constexpr xieite::math::BigInteger<Limb> power(const xieite::math::BigInteger<Limb>& exponent) const noexcept;
```
#### 2)
```cpp
template<std::integral Integral>
[[nodiscard]] constexpr xieite::math::BigInteger<Limb> power(Integral exponent) const noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    xieite::math::BigInteger bigIntegral = 2;

    std::println("{}", bigIntegral.power(3).string());
}
```
Output:
```
8
```
