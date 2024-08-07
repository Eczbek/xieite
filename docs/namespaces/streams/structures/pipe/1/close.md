# [xieite](../../../../../xieite.md)\:\:[streams](../../../../../streams.md)\:\:[Pipe](../../../pipe.md)\:\:close\(\)
Defined in header [<xieite/streams/pipe.hpp>](../../../../../../include/xieite/streams/pipe.hpp)

&nbsp;

## Description
Closes a pipe. Automatically called upon destruction.

&nbsp;

## Synopsis
#### 1)
```cpp
int close() noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/streams/pipe.hpp"

int main() {
    auto pipe = xieite::streams::Pipe("echo Hello, world!", "r");

    std::println("{}", pipe.close());
}
```
Possible output:
```
0
```
