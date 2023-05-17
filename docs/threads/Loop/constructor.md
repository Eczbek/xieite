# [`xieite`](../../../README.md)`::`[`threads`](../../../docs/threads.md)`::`[`Loop`](../../../docs/threads/Loop.md)`::Loop`
Defined in header [`<xieite/threads/Loop.hpp>`](../../../include/xieite/threads/Loop.hpp)

<br/>

Constructs a `xieite::threads::Loop`, starts running a callback constantly.

<br/><br/>

## Synopsis

<br/>

```cpp
Loop(const std::invocable<>& callback) noexcept;
```
### Parameters
- `callback` - An `auto` constant reference, satisfying `std::invocable` with no arguments
