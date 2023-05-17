# [`xieite`](../../../README.md)`::`[`threads`](../../../docs/threads.md)`::`[`Timeout`](../../../docs/threads/Timeout.md)`::Timeout`
Defined in header [`<xieite/threads/Timeout.hpp>`](../../../include/xieite/threads/Timeout.hpp)

<br/>

Constructs a `xieite::threads::Timeout`, starts waiting for a set amount of time before calling a callback.

<br/><br/>

## Synopsis

<br/>

```cpp
Timeout(const std::invocable<>& callback, const xieite::concepts::TemporalDuration auto duration) noexcept;
```
### Parameters
- `callback` - An `auto` constant reference, satisfying `std::invocable` with no arguments
- `duration` - An `auto` copy, satisfying `xieite::concepts::TemporalDuration`
