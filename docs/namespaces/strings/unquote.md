# [xieite](../../xieite.md)\:\:[strings](../../strings.md)\:\:unquote\(\)
Defined in header [<xieite/strings/unquote.hpp>](../../../include/xieite/strings/unquote.hpp)

&nbsp;

## Description
"Unquotes" a string, removing quotes and escaping escaped characters.

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
#include "xieite/strings/unquote.hpp"

int main() {
    std::println("{}", xieite::strings::unquote("\"Something \\\"quoted\\\" and \\\\escaped\""));
}
```
Output:
```
Something "quoted" and \escaped
```
