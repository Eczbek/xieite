# [xieite](../../../../../../xieite.md)\:\:[threads](../../../../../../threads.md)\:\:[Timeout](../../../../timeout.md)\:\:Timeout\(\)
Defined in header [<xieite/threads/timeout.hpp>](../../../../../../../include/xieite/threads/timeout.hpp)

&nbsp;

## Description
Constructs a `xieite::threads::Timeout`, starts waiting for a set amount of time before calling a callback.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Duration Duration>
Timeout(const xieite::functors::Function<void()>& callback, Duration duration) noexcept;
```

&nbsp;

## [Example](../../../../timeout.md#Example)
