# [xieite](../xieite.md)\:\:[literals](../literals.md)\:\: \(strings\)
Defined in header [<xieite/literals/strings.hpp>](../../include/xieite/literals/strings.hpp)

&nbsp;

## Description
Stringification!

&nbsp;

## Synopses
#### 1)
```cpp
template<char... characters>
constexpr std::string operator""_s() noexcept;
```
#### 2)
```cpp
template<char... characters>
constexpr std::string_view operator""_sv() noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/literals/strings.hpp>

int main() {
    using namespace xieite::literals;

    std::cout << 0xFF7F00_sv << '\n';
}
```
Output:
```
0xFF7F00
```
