# [xieite](../../../../../xieite.md)\:\:[streams](../../../../../streams.md)\:\:[File](../../../file.md)\:\:release\(\)
Defined in header [<xieite/streams/file.hpp>](../../../../../../include/xieite/streams/file.hpp)

&nbsp;

## Description
Releases the stored `std::FILE*` and returns it.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] std::FILE* release() noexcept;
```

&nbsp;

## Example
```cpp
#include <cstdio>
#include <print>
#include "xieite/streams/file.hpp"

int main() {
    auto file = xieite::streams::File("test.txt");

    std::FILE* stream = file.release();
    // The stream will no longer be closed automatically
    std::fclose(stream);
}
```
