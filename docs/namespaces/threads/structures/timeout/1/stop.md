# [xieite](../../../../../xieite.md)\:\:[threads](../../../../../threads.md)\:\:[Timeout](../../../timeout.md)\:\:stop
Defined in header [<xieite/threads/timeout.hpp"](../../../../../../include/xieite/threads/timeout.hpp)

&nbsp;

## Description
Stops a `xieite::threads::Timeout` and its callback call. Returns execution to the caller thread, without waiting for the timout to complete.

&nbsp;

## Synopses
#### 1)
```cpp
void stop() noexcept;
```
