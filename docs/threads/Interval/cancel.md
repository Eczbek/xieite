# `xieite::threads::Interval::cancel`
Defined in header [`<xieite/threads/Interval.hpp>`](https://github.com/Eczbek/xieite/tree/main/include/xieite/threads/Interval.hpp)

<br/>

Cancels a `xieite::threads::Interval` and stops further callbacks. Immediately returns execution to the caller thread, without waiting for the loop to complete.

<br/><br/>

## Synopsis

<br/>

```cpp
void cancel() noexcept;
```

<br/><br/>

## See also
- [`xieite::threads::Interval`](https://github.com/Eczbek/xieite/tree/main/docs/threads/Interval.md)
