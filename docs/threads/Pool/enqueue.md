# [xieite](../../../README.md)::[threads](../../threads.md)::[Pool](../Pool.md)::enqueue
Defined in header [<xieite/threads/Pool.hpp>](../../../include/xieite/threads/Pool.hpp)

<br/>

Enqueues a job to be executed when a thread is available

<br/><br/>

## Synopsis

<br/>

```cpp
void enqueue(const std::function<void()>& callback) noexcept;
```
### Parameters
- `callback` - A constant reference to a `std::function` which takes no arguments and returns `void`
