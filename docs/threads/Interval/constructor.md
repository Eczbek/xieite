# [xieite](../../xieite.md)::[threads](../../threads.md)::[Interval](../Interval.md)::Interval
Defined in header [<xieite/threads/Interval.hpp>](../../../include/xieite/threads/Interval.hpp)

<br/>

Constructs a `xieite::threads::Interval`, starts running a callback between set delays

<br/><br/>

## Synopsis

<br/>

```cpp
Interval(const std::invocable auto& callback, const xieite::concepts::TemporalDuration auto duration) noexcept;
```
### Parameters
- `callback` - A constant reference to a value of any type satisfying `std::invocable` with no arguments
- `duration` - A value of any type satisfying `xieite::concepts::TemporalDuration`
