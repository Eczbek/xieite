# [xieite](../../xieite.md)\:\:[strings](../../strings.md)\:\:hash
Defined in header [<xieite/strings/hash.hpp>](../../../include/xieite/strings/hash.hpp)

&nbsp;

## Description
Hashes a value. Currently only supports `std::string`s. Collisions may occur.

&nbsp;

## Synopses
#### 1)
```cpp
[[nodiscard]] constexpr std::size_t hash(std::string_view string) noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/strings/hash.hpp>

int main() {
    switch (xieite::strings::hash("banana")) {
        case xieite::strings::hash("apple"):
            std::cout << "1\n";
            break;
        case xieite::strings::hash("banana"):
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
