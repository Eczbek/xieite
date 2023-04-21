# [`xieite`](../../../README.md)`::`[`threads`](../../../docs/threads.md)`::`[`Interval`](../../../docs/threads/Interval.md)`::Interval`
Defined in header [`<xieite/threads/Interval.hpp>`](../../../include/xieite/threads/Interval.hpp)

<br/>

Constructs a `xieite::threads::Interval`, starts running a callback between set delays.

<br/><br/>

## Synopsis

<br/>

```cpp
template<std::invocable<> Invocable>
Interval(Invocable&& callback, const xieite::concepts::TemporalDuration auto duration) noexcept;
```
### Template parameters
- `Invocable` - An invocable type, satisfying `std::invocable` with no parameters
### Parameters
- `callback` - An `Invocable` right-value reference
- `duration` - An `auto` copy, satisfying `xieite::concepts::TemporalDuration`

<br/><br/>

## See also
- [`xieite::concepts::TemporalDuration`](../../../docs/concepts/TemporalDuration.md)
