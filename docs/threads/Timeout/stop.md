# [xieite](../../../README.md)::[threads](../../threads.md)::[Timeout](../Timeout.md)::stop
Defined in header [<xieite/threads/Timeout.hpp>](../../../include/xieite/threads/Timeout.hpp)

<br/>

Stops a `xieite::threads::Timeout` and its callback call. Returns execution to the caller thread, without waiting for the timout to complete

<br/><br/>

## Synopsis

<br/>

```cpp
void stop() noexcept;
```
