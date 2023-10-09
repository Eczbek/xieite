# [xieite](../../../../../../xieite.md)\:\:[threads](../../../../../../threads.md)\:\:[Loop](../../../../loop.md)\:\:Loop
Defined in header [<xieite/threads/loop.hpp>](../../../../../../../include/xieite/threads/loop.hpp)

&nbsp;

## Description
Constructs a `xieite::threads::Loop`, starts running a callback constantly.

&nbsp;

## Synopses
#### 1)
```cpp
template<std::invocable<> Functor>
Loop(const Functor& callback) noexcept;
```
