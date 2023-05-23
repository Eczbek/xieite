# [`xieite`](../../README.md)`::`[`concepts`](../../docs/concepts.md)`::Function`
Defined in header [`<xieite/concepts/Functional.hpp>`](../../include/xieite/concepts/Functional.hpp)

<br/>

Specifies that type `Invocable` is function-like.

<br/><br/>

## Synopsis

<br/>

```cpp
template<typename Invocable, typename ResultOfParameters>
concept Function = xieite::traits::isFunction<Invocable, ResultOfParameters>;
```
### Template parameters
- `Invocable` - An invocable type
- `ResultOfParameters` - A function-like type in the format of `void(bool, int)`, where `bool` and `int` are parameters and `void` is the return type
