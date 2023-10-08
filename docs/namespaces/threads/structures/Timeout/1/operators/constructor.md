# [xieite](../../../../../../xieite.md)\:\:[threads](../../../../../../threads.md)\:\:[Timeout](../../../../Timeout.md)\:\:Timeout
Defined in header [<xieite/threads/Timeout.hpp>](../../../../../../../include/xieite/threads/Timeout.hpp)

&nbsp;

## Description
Constructs a `xieite::threads::Timeout`, starts waiting for a set amount of time before calling a callback.

&nbsp;

## Synopses
#### 1)
```cpp
template<std::invocable<> Functor, xieite::concepts::ChronoDuration ChronoDuration>
Timeout(const Functor& callback, ChronoDuration duration) noexcept;
```
