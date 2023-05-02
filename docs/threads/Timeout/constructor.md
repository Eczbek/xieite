# [`xieite`](../../../README.md)`::`[`threads`](../../../docs/threads.md)`::`[`Timeout`](../../../docs/threads/Timeout.md)`::Timeout`
Defined in header [`<xieite/threads/Timeout.hpp>`](../../../include/xieite/threads/Timeout.hpp)

<br/>

Constructs a `xieite::threads::Timeout`, starts waiting for a set amount of time before calling a callback.

<br/><br/>

## Synopsis

<br/><br/>

```cpp
template<std::invocable<> Invocable>
Timeout(Invocable&& callback, const xieite::concepts::TemporalDuration auto duration) noexcept;
```
### Template parameters
- `Invocable` - An invocable type, satisfying `std::invocable` with no parameters
### Parameters
- `callback` - An `Invocable` right-value reference
- `duration` - An `auto` copy, satisfying `xieite::concepts::TemporalDuration`
