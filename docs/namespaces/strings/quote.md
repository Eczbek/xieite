# [xieite](../../xieite.md)\:\:[strings](../../strings.md)\:\:quote\(\)
Defined in header [<xieite/strings/quote.hpp>](../../../include/xieite/strings/quote.hpp)

&nbsp;

## Description
Replicates `std::quoted` but without streams and more `constexpr`.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] constexpr std::string quote(std::string_view value, char delimiter = '"', char escape = '\\') noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/strings/quote.hpp"

int main() {
    std::println("{}", xieite::strings::quote("Something \"quoted\" and \\escaped"));
}
```
Output:
```
"Something \"quoted\" and \\escaped"
```
