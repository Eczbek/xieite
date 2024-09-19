# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:reverse\<\>\(\)
Defined in fragment [xieite:math.reverse](../../../src/math/reverse.cpp)

&nbsp;

## Description
Reverses the digits of an integral of any radix. Allows negative radices.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::integral Integral>
[[nodiscard]] constexpr Integral reverse(Integral value, std::type_identity_t<Integral> radix = 10) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", xieite::math::reverse(12345));
}
```
Output:
```
54321
```
