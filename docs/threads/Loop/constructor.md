# [xieite](../../xieite.md)::[threads](../../threads.md)::[Loop](../Loop.md)::Loop
Defined in header [<xieite/threads/Loop.hpp>](../../../include/xieite/threads/Loop.hpp)

<br/>

Constructs a `xieite::threads::Loop`, starts running a callback constantly

<br/><br/>

## Synopsis

<br/>

```cpp
template<std::invocable<> Invocable>
Loop(const Invocable& callback) noexcept;
```
### Template parameters
- `Invocable` - A type satisfying `std::invocable`
### Parameters
- `callback` - A constant `Invocable` reference
