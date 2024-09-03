# [xieite](../../../../../../xieite.md)\:\:[threads](../../../../../../threads.md)\:\:[Timeout](../../../../timeout.md)\:\:Timeout\<\>\(\)
Defined in fragment [xieite:threads.Timeout](../../../../../../../src/threads/timeout.cpp)

&nbsp;

## Description
Constructs a `xieite::threads::Timeout`, starts waiting for a set amount of time before calling a callback.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::invocable<> Functor, xieite::concepts::Duration Duration>
Timeout(Functor&& callback, Duration duration) noexcept;
```

&nbsp;

## [Example](../../../../timeout.md#Example)
