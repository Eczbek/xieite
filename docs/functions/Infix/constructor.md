# [`xieite`](../../../README.md)`::`[`functions`](../../../docs/functions.md)`::`[`Infix<Result, LeftParameter, RightParameter>`](../../../docs/functions/Infix.md)`::Infix`
Defined in header [`<xieite/functions/Infix.hpp>`](../../../include/xieite/functions/Infix.hpp)

<br/>

Constructs a `xieite::functions::Infix` thing.

<br/><br/>

## Synopsis

<br/>

```cpp
constexpr Infix(Result(*)(LeftParameter, RightParameter) callback) noexcept;
```
### Parameters
- `callback` - A function-like instance
