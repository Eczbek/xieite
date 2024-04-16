# [xieite](../../../../../xieite.md)\:\:[streams](../../../../../streams.md)\:\:[Pipe](../../../pipe.md)\:\:file\(\)
Defined in header [<xieite/streams/pipe.hpp>](../../../../../../include/xieite/streams/pipe.hpp)

&nbsp;

## Description
Returns the underlying file stream.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] std::FILE* file() const noexcept;
```

&nbsp;

## Example
```cpp
#include <cstdio>
#include <print>
#include "xieite/streams/pipe.hpp"
#include "xieite/streams/read.hpp"

int main() {
    auto pipe = xieite::streams::Pipe("echo Hello, world!", "r");

    std::println("{}", xieite::streams::read(pipe.file()));
}
```
Possible output:
```
Hello, world!
```
