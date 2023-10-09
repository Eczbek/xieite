# [xieite](../../../../../../xieite.md)\:\:[threads](../../../../../../threads.md)\:\:[Interval](../../../../interval.md)\:\:Interval
Defined in header [<xieite/threads/interval.hpp>](../../../../../../../include/xieite/threads/interval.hpp)

&nbsp;

## Description
Constructs a `xieite::threads::Interval`, starts running a callback between set delays.

&nbsp;

## Synopses
#### 1)
```cpp
template<std::invocable<> Functor, xieite::concepts::TemporalDuration TemporalDuration>
Interval(const Functor& callback, TemporalDuration duration) noexcept;
```
