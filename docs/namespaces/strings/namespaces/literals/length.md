# [xieite](../../../../xieite.md)\:\:[strings](../../../../strings.md)\:\:[literals](../../literals.md)\:\:\_length
Defined in header [<xieite/strings/literals/length.hpp>](../../../../../include/xieite/strings/literals/length.hpp)

&nbsp;

## Description
Length.

&nbsp;

## Synopses
#### 1)
```cpp
template<char... characters>
[[nodiscard]] constexpr std::size_t operator""_length() noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/strings/literals/length.hpp>

int main() {
    using namespace xieite::strings::literals;

    std::cout << 12345_length << '\n';
}
```
Output:
```
5
```
