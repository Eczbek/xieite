# [xieite](../../../../../xieite.md)\:\:[threads](../../../../../threads.md)\:\:[Pool](../../../pool.md)\:\:enqueue\<\>\(\)
Defined in fragment [xieite:threads.Pool](../../../../../../src/threads/pool.cpp)

&nbsp;

## Description
Enqueues a job to be executed when a thread is available.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::invocable<> Functor>
/* discardable */ std::future<void> enqueue(Functor&& functor) noexcept;
```

&nbsp;

## [Example](../../../pool.md#Example)
