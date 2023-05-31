# [xieite](../../README.md)::[concepts](../concepts.md)::Functable
Defined in header [<xieite/concepts/Functable.hpp>](../../include/xieite/concepts/Functable.hpp)

<br/>

Specifies that a type is functable

<br/><br/>

## Synopsis

<br/>

```cpp
template<typename Invocable, typename ResultOfParameters>
concept Functable = xieite::traits::isFunctable<Invocable, ResultOfParameters>;
```
### Template parameters
- `Invocable` - An invocable type
- `ResultOfParameters` - A function type, like `void(int, bool)`
