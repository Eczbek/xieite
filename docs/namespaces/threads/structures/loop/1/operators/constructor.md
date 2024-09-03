# [xieite](../../../../../../xieite.md)\:\:[threads](../../../../../../threads.md)\:\:[Loop](../../../../loop.md)\:\:Loop\(\)
Defined in fragment [xieite:threads.Loop](../../../../../../../src/threads/loop.cpp)

&nbsp;

## Description
Constructs a `xieite::threads::Loop`, starts running a callback constantly.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::invocable<> Functor>
Loop(Functor&& callback) noexcept;
```

&nbsp;

## [Example](../../../../loop.md#Example)
