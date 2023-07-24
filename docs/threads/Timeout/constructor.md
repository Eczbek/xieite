# [xieite](../../xieite.md)::[threads](../../threads.md)::[Timeout](../Timeout.md)::Timeout
Defined in header [<xieite/threads/Timeout.hpp>](../../../include/xieite/threads/Timeout.hpp)

<br/>

Constructs a `xieite::threads::Timeout`, starts waiting for a set amount of time before calling a callback

<br/><br/>

## Synopsis

<br/>

```cpp
template<std::invocable<> Invocable, xieite::concepts::TemporalDuration TemporalDuration>
Timeout(const Invocable& callback, const TemporalDuration duration) noexcept;
```
### Template parameters
- `Invocable` - A type satisfying `std::invocable`
- `TemporalDuration` - A type satisfying `xieite::concepts::TemporalDuration`
### Parameters
- `callback` - A constant `Invocable` reference
- `duration` - A `TemporalDuration`
