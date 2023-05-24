# [`xieite`](../../../README.md)`::`[`threads`](../../../docs/threads.md)`::`[`Interval`](../../../docs/threads/Interval.md)`::Interval`
Defined in header [`<xieite/threads/Interval.hpp>`](../../../include/xieite/threads/Interval.hpp)

<br/>

Constructs a `xieite::threads::Interval`, starts running a callback between set delays.

<br/><br/>

## Synopsis

<br/>

```cpp
Interval(const std::invocable<>& callback, const xieite::concepts::TemporalDuration auto duration) noexcept;
```
### Parameters
- `callback` - An `auto` constant reference, satisfying `std::invocable` with no arguments
- `duration` - An `auto` copy, satisfying `xieite::concepts::TemporalDuration`