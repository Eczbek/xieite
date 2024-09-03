# [xieite](../../../../../xieite.md)\:\:[math](../../../../../math.md)\:\:[BigInteger<Limb>](../../../big_integer.md)\:\:string\(\)
Defined in fragment [xieite:math.BigInteger](../../../../../../src/math/big_integer.cpp)

&nbsp;

## Description
Converts a `xieite::math::BigInteger<Limb>` to a `std::string`.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] constexpr std::string string(xieite::math::SignedSize radix = 10, xieite::strings::NumberComponents components = xieite::strings::NumberComponents()) const noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", xieite::math::BigInteger(418).string());
}
```
Output:
```
418
```
