# [xieite](../../xieite.md)\:\:[hashes](../../hashes.md)\:\:md5\(\)
Defined in header [<xieite/hashes/md5.hpp>](../../../include/xieite/hashes/md5.hpp)

&nbsp;

## Description
Generates a 128-bit hash of a string using the MD5 algorithm.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::String String = std::string>
[[nodiscard]] constexpr String md5(const xieite::strings::View<String> value) noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/hashes/md5.hpp"

int main() {
    std::println("{}", xieite::hashes::md5("Hello, world!"));
}
```
Output:
```
8B0866384E860A3929B7FC07B8447E9B
```
