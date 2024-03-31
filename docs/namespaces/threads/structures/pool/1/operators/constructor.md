# [xieite](../../../../../../xieite.md)\:\:[threads](../../../../../../threads.md)\:\:[Pool](../../../../pool.md)\:\:Pool\(\)
Defined in header [<xieite/threads/pool.hpp>](../../../../../../../include/xieite/threads/pool.hpp)

&nbsp;

## Description
Constructs a `xieite::threads::Pool`, creates initial threads.

&nbsp;

## Synopsis
#### 1)
```cpp
Pool(std::size_t threadCount = std::thread::hardware_concurrency());
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/threads/pool.hpp"

int main() {
    auto pool = xieite::threads::Pool(4);

    std::println("{}", pool.getThreadCount());
}
```
Output:
```
4
```
