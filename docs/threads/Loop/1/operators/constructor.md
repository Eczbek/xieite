# [xieite](../../../../xieite.md)\:\:[threads](../../../../threads.md)\:\:[Loop](../../../Loop.md)\:\:Loop
Defined in header [<xieite/threads/Loop.hpp>](../../../../../include/xieite/threads/Loop.hpp)

&nbsp;

## Description
Constructs a `xieite::threads::Loop`, starts running a callback constantly.

&nbsp;

## Synopses
#### 1)
```cpp
template<std::invocable<> Invocable>
Loop(const Invocable& callback) noexcept;
```
