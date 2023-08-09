# [xieite](../../xieite.md)\:\:[threads](../../threads.md)\:\:[Timeout](../Timeout.md)\:\:stop
Defined in header [<xieite/threads/Timeout.hpp>](../../../include/xieite/threads/Timeout.hpp)

&nbsp;

## Description
Stops a `xieite::threads::Timeout` and its callback call. Returns execution to the caller thread, without waiting for the timout to complete.

&nbsp;

## Synopses
#### 1)
```cpp
void stop() noexcept;
```
