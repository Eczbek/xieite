# [xieite](../../../../../xieite.md)\:\:[math](../../../../../math.md)\:\:[BigInteger<Limb>](../../../big_integer.md)\:\:root\<\>\(\)
Defined in fragment [xieite:math.BigInteger](../../../../../../src/math/big_integer.cpp)

&nbsp;

## Description
Computes any root of a `xieite::math::BigInteger<Limb>`. Taking the root of a negative value throws `std::out_of_range`.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] constexpr xieite::math::BigInteger<Limb> root(const xieite::math::BigInteger<Limb>& degree) const;
```
#### 2)
```cpp
template<std::integral Integral>
[[nodiscard]] constexpr xieite::math::BigInteger<Limb> root(Integral degree) const;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    xieite::math::BigInteger bigIntegral = 8;

    std::println("{}", bigIntegral.root(3).string());
}
```
Output:
```
2
```
