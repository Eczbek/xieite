# [xieite](../xieite.md)::[concepts](../concepts.md)::Functable
Defined in header [<xieite/concepts/Functable.hpp>](../../include/xieite/concepts/Functable.hpp)

<br/>

Specifies that a type is functable

<br/><br/>

## Synopsis

<br/>

```cpp
template<typename Functor, typename Type>
concept Functable = xieite::traits::isFunctable<Functor, Type> && xieite::traits::isFunctable<Type, Functor>;
```
### Template parameters
- `Functor` - Any type
- `Type` - The function type, like `void(int, bool)`
