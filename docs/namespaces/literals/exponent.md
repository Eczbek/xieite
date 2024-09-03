# [xieite](../../xieite.md)\:\:[literals](../../literals.md)\:\:exponent
Defined in fragment [xieite:literals.exponent](../../../src/literals/exponent.cpp)

&nbsp;

## Description
`operator**` go brrr

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] constexpr auto operator""_exponent(unsigned long long int value) noexcept;
```
#### 2)
```cpp
[[nodiscard]] constexpr auto operator""_exponent(long double value) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    using namespace xieite::literals::exponent;

    std::println("{}", 4 ** 4_exponent);
    std::println("{}", 25 ** 0.5_exponent);
    std::println("{}", 999 ** 0_exponent);
}
```
Output:
```
256
5
1
```
