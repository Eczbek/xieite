# [xieite](../../../../../xieite.md)\:\:[threads](../../../../../threads.md)\:\:[Interval](../../../interval.md)\:\:stop
Defined in header [<xieite/threads/interval.hpp>](../../../../../../include/xieite/threads/interval.hpp)

&nbsp;

## Description
Stops a `xieite::threads::Interval`, and further callback calls. Immediately returns execution to the caller thread, without waiting for the loop to complete.

&nbsp;

## Synopses
#### 1)
```cpp
void stop() noexcept;
```
