# [xieite](../../xieite.md)\:\:[threads](../../threads.md)\:\:[Pool](../Pool.md)\:\:Pool
Defined in header [<xieite/threads/Pool.hpp>](../../../include/xieite/threads/Pool.hpp)

&nbsp;

## Description
Constructs a `xieite::threads::Pool`, creates initial threads

&nbsp;

## Synopsis
```cpp
Pool(std::size_t threadCount = std::thread::hardware_concurrency());
```
#### Function parameters
- `threadCount` - A `std::size_t`, the number of threads to create. Set to `std::thread::hardware_concurrency` by default, which usually correlates with the optimal number of threads
