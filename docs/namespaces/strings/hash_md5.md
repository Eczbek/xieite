# [xieite](../../xieite.md)\:\:[strings](../../strings.md)\:\:hashMd5
Defined in header [<xieite/strings/hash_md5.hpp"](../../../include/xieite/strings/hash_md5.hpp)

&nbsp;

## Description
Generates an MD5 hash.

&nbsp;

## Synopses
#### 1)
```cpp
[[nodiscard]] constexpr std::string hashMd5(std::string_view value) noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include "xieite/strings/hash_md5.hpp"

int main() {
    std::cout << xieite::strings::hashMd5("Hello, world!") << '\n';
}
```
Output:
```
6cd3556deb0da54bca060b4c39479839
```
