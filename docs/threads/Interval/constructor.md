# `xieite::threads::Interval::Interval`
Defined in header [`<xieite/threads/Interval.hpp>`](https://github.com/Eczbek/xieite/tree/main/include/xieite/threads/Interval.hpp)

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
- [`xieite::concepts::TemporalDuration`](https://github.com/Eczbek/xieite/tree/main/docs/concepts/TemporalDuration.md)
- [`xieite::threads::Interval`](https://github.com/Eczbek/xieite/tree/main/docs/threads/Interval.md)
