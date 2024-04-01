# [xieite](../../xieite.md)\:\:[threads](../../threads.md)\:\:identifier
Defined in header [<xieite/threads/identifier.hpp>](../../../include/xieite/threads/identifier.hpp)

&nbsp;

## Description
Gives an identifier to each unique thread.

&nbsp;

## Synopsis
#### 1)
```cpp
inline thread_local const std::size_t identifier = /* ... */;
```

&nbsp;

## Example
```cpp
#include <print>
#include <thread>
#include "xieite/threads/identifier.hpp"

int main() {
    auto x = std::jthread([] {
        std::println("{}", xieite::threads::identifier);
    });

    auto y = std::jthread([] {
        std::println("{}", xieite::threads::identifier);
    });

    auto z = std::jthread([] {
        std::println("{}", xieite::threads::identifier);
    });
}
```
Possible output:
```
0
1
2
```
