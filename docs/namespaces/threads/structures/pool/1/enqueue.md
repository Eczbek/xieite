# [xieite](../../../../../xieite.md)\:\:[threads](../../../../../threads.md)\:\:[Pool](../../../pool.md)\:\:enqueue\(\)
Defined in header [<xieite/threads/pool.hpp>](../../../../../../include/xieite/threads/pool.hpp)

&nbsp;

## Description
Enqueues a job to be executed when a thread is available.

&nbsp;

## Synopsis
#### 1)
```cpp
void enqueue(const std::function<void()>& callback) noexcept;
```

&nbsp;

## [Example](../../../pool.md#Example)
