# [xieite](../../../../../xieite.md)\:\:[threads](../../../../../threads.md)\:\:[Loop](../../../loop.md)\:\:stop\(\)
Defined in header [<xieite/threads/loop.hpp>](../../../../../../include/xieite/threads/loop.hpp)

&nbsp;

## Description
Stops a `xieite::threads::Loop`, and further callback calls.

&nbsp;

## Synopsis
#### 1)
```cpp
void stop() noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/threads/loop.hpp"

int main() {
    auto loop = xieite::threads::Loop([] {
        std::println("xyz");
    });

    loop.stop();
}
```
Possible output:
```
```
