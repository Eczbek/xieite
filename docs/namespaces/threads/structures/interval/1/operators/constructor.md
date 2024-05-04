# [xieite](../../../../../../xieite.md)\:\:[threads](../../../../../../threads.md)\:\:[Interval](../../../../interval.md)\:\:Interval\<\>\(\)
Defined in header [<xieite/threads/interval.hpp>](../../../../../../../include/xieite/threads/interval.hpp)

&nbsp;

## Description
Constructs a `xieite::threads::Interval`, starts running a callback between set delays.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Duration Duration_>
Interval(const xieite::functors::Function<void()>& callback, Duration_ duration) noexcept;
```

&nbsp;

## [Example](../../../../interval.md#Example)
