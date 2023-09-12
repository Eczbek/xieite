# [xieite](../../../../xieite.md)\:\:[threads](../../../../threads.md)\:\:[Interval](../../../Interval.md)\:\:Interval
Defined in header [<xieite/threads/Interval.hpp>](../../../../../include/xieite/threads/Interval.hpp)

&nbsp;

## Description
Constructs a `xieite::threads::Interval`, starts running a callback between set delays.

&nbsp;

## Synopses
#### 1)
```cpp
template<std::invocable<> Invocable, xieite::concepts::ChronoDuration ChronoDuration>
Interval(const Invocable& callback, ChronoDuration duration) noexcept;
```
