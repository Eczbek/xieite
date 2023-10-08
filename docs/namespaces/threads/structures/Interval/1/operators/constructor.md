# [xieite](../../../../../../xieite.md)\:\:[threads](../../../../../../threads.md)\:\:[Interval](../../../../Interval.md)\:\:Interval
Defined in header [<xieite/threads/Interval.hpp>](../../../../../../../include/xieite/threads/Interval.hpp)

&nbsp;

## Description
Constructs a `xieite::threads::Interval`, starts running a callback between set delays.

&nbsp;

## Synopses
#### 1)
```cpp
template<std::invocable<> Functor, xieite::concepts::ChronoDuration ChronoDuration>
Interval(const Functor& callback, ChronoDuration duration) noexcept;
```
