# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:parse\<\>\(\)
Defined in fragment [xieite:math.parse](../../../src/math/parse.cpp)

&nbsp;

## Description
Parses a number string in any radix. Allows negative radices. Is case-sensitive.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Arithmetic Arithmetic>
[[nodiscard]] constexpr Arithmetic parse(std::string_view value, std::conditional_t<std::floating_point<Arithmetic>, xieite::math::SignedSize, Arithmetic> radix = 10, xieite::strings::NumberComponents components = xieite::strings::NumberComponents()) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", xieite::math::parse<int>("G4H3", 21));
}
```
Output:
```
150300
```
