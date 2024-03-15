# [xieite](../../xieite.md)\:\:[strings](../../strings.md)\:\:hashDjb2
Defined in header [<xieite/strings/hash_djb2.hpp>](../../../include/xieite/strings/hash_djb2.hpp)

&nbsp;

## Description
Generates a djb2 hash.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] constexpr std::size_t hashDjb2(std::string_view value) noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/strings/hash_djb2.hpp"

int main() {
    switch (xieite::strings::hashDjb2("banana")) {
        case xieite::strings::hashDjb2("apple"):
            std::println("1");
            break;
        case xieite::strings::hashDjb2("banana"):
            std::println("2");
            break;
        default:
            std::println("3");
    }
}
```
Output:
```
2
```
