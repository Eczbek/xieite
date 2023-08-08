# [xieite](../../xieite.md)\:\:[threads](../../threads.md)\:\:[Interval](../Interval.md)\:\:stop
Defined in header [<xieite/threads/Interval.hpp>](../../../include/xieite/threads/Interval.hpp)

&nbsp;

## Description
Stops a `xieite::threads::Interval`, and further callback calls. Immediately returns execution to the caller thread, without waiting for the loop to complete

&nbsp;

## Synopsis
```cpp
void stop() noexcept;
```
