# [xieite](../../xieite.md)\:\:[hashes](../../hashes.md)\:\:djb2\(\)
Defined in header [<xieite/hashes/djb2.hpp>](../../../include/xieite/hashes/djb2.hpp)

&nbsp;

## Description
Hashes a string using the relatively fast djb2 algorithm.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] constexpr std::size_t djb2(const std::string_view value) noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/hashes/djb2.hpp"

int main() {
    switch (xieite::hashes::djb2("apple")) {
    case xieite::hashes::djb2("banana"):
        std::println("1");
        break;
    case xieite::hashes::djb2("potato"):
        std::println("2");
        break;
    case xieite::hashes::djb2("apple"):
        std::println("3");
        break;
    default:
        std::println("4");
        break;
    }
}
```
Output:
```
3
```
