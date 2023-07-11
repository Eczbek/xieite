# [xieite](../../../README.md)::[threads](../../threads.md)::[Pool](../Pool.md)::Pool
Defined in header [<xieite/threads/Pool.hpp>](../../../include/xieite/threads/Pool.hpp)

<br/>

Constructs a `xieite::threads::Pool`, creates initial threads

<br/><br/>

## Synopsis

<br/>

```cpp
Pool(std::size_t threadCount = std::thread::hardware_concurrency());
```
### Parameters
- `threadCount` - A `std::size_t` copy, the number of threads to create. Set to `std::thread::hardware_concurrency` by default, which usually correlates with the optimal number of threads
