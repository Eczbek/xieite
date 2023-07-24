# [xieite](../../xieite.md)::[threads](../../threads.md)::[Interval](../Interval.md)::Interval
Defined in header [<xieite/threads/Interval.hpp>](../../../include/xieite/threads/Interval.hpp)

<br/>

Constructs a `xieite::threads::Interval`, starts running a callback between set delays

<br/><br/>

## Synopsis

<br/>

```cpp
template<std::invocable<> Invocable, xieite::concepts::TemporalDuration TemporalDuration>
Interval(const Invocable& callback, TemporalDuration duration) noexcept;
```
### Template parameters
- `Invocable` - A type satisfying `std::invocable`
- `TemporalDuration` - A type satisfying `xieite::concepts::TemporalDuration`
### Parameters
- `callback` - A constant `Invocable` reference
- `duration` - A `TemporalDuration`
