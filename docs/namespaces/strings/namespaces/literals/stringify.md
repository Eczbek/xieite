# [xieite](../../../../xieite.md)\:\:[strings](../../../../strings.md)\:\:[literals](../../literals.md)\:\:stringify
Defined in header [<xieite/strings/literals/stringify.hpp>](../../../../../include/xieite/strings/literals/stringify.hpp)

&nbsp;

## Description
Stringification.

&nbsp;

## Synopses
#### 1)
```cpp
template<char... characters>
[[nodiscard]] constexpr std::string operator""_stringify() noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/strings/literals/strigify.hpp>

int main() {
    using namespace xieite::strings::literals::stringify;

    std::cout << 0xFF7F00_stringify << '\n';
}
```
Output:
```
0xFF7F00
```
