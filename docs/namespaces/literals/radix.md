# [xieite](../../xieite.md)\:\:[literals](../../literals.md)\:\:radix
Defined in fragment [xieite:literals.radix](../../../src/literals/radix.cpp)

&nbsp;

## Description
A namespace for a literal that evaluates to the radix of a numeric literal.

&nbsp;

## Synopsis
#### 1)
```cpp
template<char... characters>
[[nodiscard]] constexpr std::size_t operator""_radix() noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    using namespace xieite::literals::radix;

    std::println("{}", 999_radix);
    std::println("{}", 0777_radix);
    std::println("{}", 0xFFF_radix);
    std::println("{}", 0b111_radix);
}
```
Output:
```
10
8
16
2
```
