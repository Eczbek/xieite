# [xieite](../../xieite.md)\:\:[threads](../../threads.md)\:\:[Interval](../Interval.md)\:\:Interval
Defined in header [<xieite/threads/Interval.hpp>](../../../include/xieite/threads/Interval.hpp)

&nbsp;

## Description
Constructs a `xieite::threads::Interval`, starts running a callback between set delays

&nbsp;

## Synopsis
```cpp
template<std::invocable<> Invocable, xieite::concepts::ChronoDuration ChronoDuration>
Interval(const Invocable& callback, ChronoDuration duration) noexcept;
```
#### Template parameters
- `Invocable` - A type satisfying `std::invocable`
- `ChronoDuration` - A type satisfying `xieite::concepts::ChronoDuration`
#### Function parameters
- `callback` - A constant `Invocable` reference
- `duration` - A `ChronoDuration`
