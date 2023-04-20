# `xieite::threads::Timeout::stop`
Defined in header [`<xieite/threads/Timeout.hpp>`](https://github.com/Eczbek/xieite/tree/main/include/xieite/threads/Timeout.hpp)

<br/>

Stops a `xieite::threads::Timeout` and its callback call. Returns execution to the caller thread, without waiting for the timout to complete.

<br/><br/>

## Synopsis

<br/>

```cpp
void stop() noexcept;
```

<br/><br/>

## See also
- [`xieite::threads::Timeout`](https://github.com/Eczbek/xieite/tree/main/docs/threads/Timeout.md)
