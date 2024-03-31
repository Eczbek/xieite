# [xieite](../../xieite.md)\:\:[strings](../../strings.md)\:\:truncate\(\)
Defined in header [<xieite/strings/truncate.hpp>](../../../include/xieite/strings/truncate.hpp)

&nbsp;

## Description
Shortens the end of a string, replacing it with a suffix.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] constexpr std::string truncate(std::string_view string, std::size_t length, std::string_view suffix = "") noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/strings/truncate.hpp"

int main() {
    std::println("{}", xieite::strings::truncate("Hello, world!", 8, "..."));
}
```
Output:
```
Hello...
```
