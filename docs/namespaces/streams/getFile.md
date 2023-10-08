# [xieite](../../xieite.md)\:\:[streams](../../streams.md)\:\:getFile
Defined in header [<xieite/streams/getFile.hpp>](../../../include/xieite/streams/getFile.hpp)

&nbsp;

## Description
Extracts a `std::FILE*` from a stream.

&nbsp;

## Synopses
#### 1)
```cpp
template<xieite::concepts::SameAsOrDerivedFromAnyAny<std::istream, std::ostream> Stream>
[[nodiscard]] inline std::FILE* getFile(const Stream& stream) noexcept;
```

&nbsp;

## Example
```cpp
#include <cstdio>
#include <iostream>
#include <xieite/streams/getFile.hpp>

int main() {
    std::fprintf(xieite::streams::getFile(std::cout), "Hello, world!\n");
}
```
Output:
```
Hello, world!
```