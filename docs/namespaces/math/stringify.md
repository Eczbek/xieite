# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:stringify\<\>\(\)
Defined in fragment [xieite:math.stringify](../../../src/math/stringify.cpp)

&nbsp;

## Description
Stringifies a number in any radix. Allows negative radices.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Arithmetic Arithmetic>
[[nodiscard]] constexpr std::string stringify(Arithmetic value, std::conditional_t<std::floating_point<Arithmetic>, xieite::math::SignedSize, Arithmetic> radix = 10, xieite::strings::NumberComponents components = xieite::strings::NumberComponents()) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", xieite::math::stringify(13, 2));
}
```
Output:
```
1101
```
