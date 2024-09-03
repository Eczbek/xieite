# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:modulo\<\>\(\)
Defined in fragment [xieite:math.modulo](../../../src/math/modulo.cpp)

&nbsp;

## Description
Computes modulus better.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Arithmetic Arithmetic>
[[nodiscard]] constexpr Arithmetic modulo(Arithmetic dividend, Arithmetic divisor) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", xieite::math::modulo(-21, 4));
}
```
Output:
```
3
```
