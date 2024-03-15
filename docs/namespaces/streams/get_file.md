# [xieite](../../xieite.md)\:\:[streams](../../streams.md)\:\:getFile
Defined in header [<xieite/streams/get_file.hpp>](../../../include/xieite/streams/get_file.hpp)

&nbsp;

## Description
Extracts a `std::FILE*` from a stream.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::SameAsOrDerivedFromAnyAny<std::istream, std::ostream> Stream>
[[nodiscard]] inline std::FILE* getFile(const Stream& stream) noexcept;
```

&nbsp;

## Example
```cpp
#include <cstdio>
#include <print>
#include "xieite/streams/get_file.hpp"

int main() {
    std::fprintf(xieite::streams::getFile(std::cout), "Hello, world!\n");
}
```
Output:
```
Hello, world!
```
