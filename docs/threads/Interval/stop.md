# [`xieite`](../../../README.md)`::`[`threads`](../../../docs/threads.md)`::`[`Interval`](../../../docs/threads/Interval.md)`::stop`
Defined in header [`<xieite/threads/Interval.hpp>`](../../../include/xieite/threads/Interval.hpp)

<br/>

Stops a `xieite::threads::Interval`, and further callback calls. Immediately returns execution to the caller thread, without waiting for the loop to complete.

<br/><br/>

## Synopsis

<br/><br/>

```cpp
void stop() noexcept;
```
