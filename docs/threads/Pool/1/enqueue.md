# [xieite](../../../xieite.md)\:\:[threads](../../../threads.md)\:\:[Pool](../../Pool.md)\:\:enqueue
Defined in header [<xieite/threads/Pool.hpp>](../../../../include/xieite/threads/Pool.hpp)

&nbsp;

## Description
Enqueues a job to be executed when a thread is available.

&nbsp;

## Synopses
#### 1)
```cpp
void enqueue(const std::function<void()>& callback) noexcept;
```
