# [xieite](../xieite.md)\:\:[system](../system.md)\:\:getStreamFile
Defined in header [<xieite/system/getStreamFile.hpp>](../../include/xieite/system/getStreamFile.hpp)

&nbsp;

## Description
Extracts a `std::FILE*` from a stream.

&nbsp;

## Synopses
#### 1)
```cpp
template<xieite::concepts::SameAsOrDerivedFromAnyAny<std::istream, std::ostream> Stream>
inline std::FILE* getStreamFile(const Stream& stream) noexcept;
```

&nbsp;

## Example
```cpp
#include <cstdio>
#include <iostream>
#include <xieite/system/getStreamFile.hpp>

int main() {
    std::fprintf(xieite::system::getStreamFile(std::cout), "Hello, world!\n");
}
```
Output:
```
Hello, world!
```
