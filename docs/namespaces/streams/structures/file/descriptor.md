# [xieite](../../../../../xieite.md)\:\:[streams](../../../../../streams.md)\:\:[File](../../../file.md)\:\:descriptor\(\)
Defined in header [<xieite/streams/file.hpp>](../../../../../../include/xieite/streams/file.hpp)

&nbsp;

## Description
Returns the underlying file descriptor.

&nbsp;

## Synopsis
#### 1)
```cpp
#if XIEITE_PLATFORM_TYPE_UNIX || XIEITE_PLATFORM_TYPE_WINDOWS
[[nodiscard]] int descriptor() const noexcept;
#endif
```

&nbsp;

## Example
```cpp
#include <cstdio>
#include <print>
#include "xieite/streams/file.hpp"

int main() {
    auto file = xieite::streams::File(stdin);

    std::println("{}", file.descriptor());
}
```
Possible output:
```
0
```
