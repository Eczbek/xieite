# `xieite::threads::Loop::Loop`
Defined in header [`<xieite/threads/Loop.hpp>`](../../../include/xieite/threads/Loop.hpp)

<br/>

Constructs a `xieite::threads::Loop`, starts running a callback constantly.

<br/><br/>

## Synopsis

<br/>

```cpp
template<std::invocable<> Invocable>
Loop(Invocable&& callback) noexcept;
```
### Template parameters
- `Invocable` - An invocable type, satisfying `std::invocable` with no parameters
### Parameters
- `callback` - An `Invocable` right-value reference

<br/><br/>

## See also
- [`xieite::threads::Loop`](../../../docs/threads/Loop.md)
