# `xieite::threads::Timeout::cancel`
Defined in header [`<xieite/threads/Timeout.hpp>`](https://github.com/Eczbek/xieite/tree/main/include/xieite/threads/Timeout.hpp)

<br/>

Cancels a `xieite::threads::Timeout` and stops its callback. Returns execution to the caller thread, without waiting for the timout to complete.

<br/><br/>

## Synopsis

<br/>

```cpp
void cancel() noexcept;
```

<br/><br/>

## See also
- [`xieite::threads::Timeout`](https://github.com/Eczbek/xieite/tree/main/docs/threads/Timeout.md)
