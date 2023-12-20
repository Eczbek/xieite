# [xieite](../../xieite.md)\:\:[strings](../../strings.md)\:\:hashDjb2
Defined in header [<xieite/strings/hash_djb2.hpp>](../../../include/xieite/strings/hash_djb2.hpp)

&nbsp;

## Description
Generates a djb2 hash.

&nbsp;

## Synopses
#### 1)
```cpp
[[nodiscard]] constexpr std::size_t hashDjb2(std::string_view value) noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/strings/hash_djb2.hpp>

int main() {
    switch (xieite::strings::hashDjb2("banana")) {
        case xieite::strings::hashDjb2("apple"):
            std::cout << "1\n";
            break;
        case xieite::strings::hashDjb2("banana"):
            std::cout << "2\n";
            break;
        default:
            std::cout << "3\n";
    }
}
```
Output:
```
2
```
