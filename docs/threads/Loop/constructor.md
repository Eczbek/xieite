# [xieite](../../xieite.md)::[threads](../../threads.md)::[Loop](../Loop.md)::Loop
Defined in header [<xieite/threads/Loop.hpp>](../../../include/xieite/threads/Loop.hpp)

<br/>

Constructs a `xieite::threads::Loop`, starts running a callback constantly

<br/><br/>

## Synopsis

<br/>

```cpp
Loop(const std::invocable auto& callback) noexcept;
```
### Parameters
- `callback` - A constant reference to a value of any type satisfying `std::invocable` with no arguments
