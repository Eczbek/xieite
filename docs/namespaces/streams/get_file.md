# [xieite](../../xieite.md)\:\:[streams](../../streams.md)\:\:getFile\(\)
Defined in header [<xieite/streams/get_file.hpp>](../../../include/xieite/streams/get_file.hpp)

&nbsp;

## Description
Extracts a `std::FILE*` from a stream. Requires GCC compiler.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Stream Stream>
[[nodiscard]] inline std::FILE* getFile(const Stream& stream) noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <print>
#include "xieite/streams/get_file.hpp"

int main() {
    std::println(xieite::streams::getFile(std::cout), "Hello, world!");
}
```
Output:
```
Hello, world!
```
