# [xieite](../../../../../xieite.md)\:\:[streams](../../../../../streams.md)\:\:[Pipe](../../../pipe.md)\:\:descriptor\(\)
Defined in header [<xieite/streams/pipe.hpp>](../../../../../../include/xieite/streams/pipe.hpp)

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
#include <print>
#include "xieite/streams/pipe.hpp"

int main() {
    auto pipe = xieite::streams::Pipe("echo Hello, world!", "r");

    std::println("{}", pipe.descriptor());
}
```
Possible output:
```
3
```
