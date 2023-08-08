# [xieite](../../xieite.md)\:\:[threads](../../threads.md)\:\:[Timeout](../Timeout.md)\:\:Timeout
Defined in header [<xieite/threads/Timeout.hpp>](../../../include/xieite/threads/Timeout.hpp)

&nbsp;

## Description
Constructs a `xieite::threads::Timeout`, starts waiting for a set amount of time before calling a callback

&nbsp;

## Synopsis
```cpp
template<std::invocable<> Invocable, xieite::concepts::ChronoDuration ChronoDuration>
Timeout(const Invocable& callback, const ChronoDuration duration) noexcept;
```
#### Template parameters
- `Invocable` - A type satisfying `std::invocable`
- `ChronoDuration` - A type satisfying `xieite::concepts::ChronoDuration`
#### Function parameters
- `callback` - A constant `Invocable` reference
- `duration` - A `ChronoDuration`
