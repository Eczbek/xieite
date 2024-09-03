# [xieite](../../../../../../xieite.md)\:\:[threads](../../../../../../threads.md)\:\:[Interval](../../../../interval.md)\:\:Interval\<\>\(\)
Defined in fragment [xieite:threads.Interval](../../../../../../../src/threads/interval.cpp)

&nbsp;

## Description
Constructs a `xieite::threads::Interval`, starts running a callback between set delays.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::invocable<> Functor, xieite::concepts::Duration Duration>
Interval(Functor&& callback, Duration duration) noexcept;
```

&nbsp;

## [Example](../../../../interval.md#Example)
