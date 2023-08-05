# [xieite](../xieite.md)::[concepts](../concepts.md)::AnyOf
Defined in header [<xieite/concepts/AnyOf.hpp>](../../include/xieite/concepts/AnyOf.hpp)

<br/>

Specifies that a type satisfies at least one of several type traits

<br/><br/>

## Synopsis

<br/>

```cpp
template<typename Type, template<typename> typename... Traits>
concept AnyOf = xieite::traits::IsAnyOf<Type, Traits...>::value;
```
### Template parameters
- `Type` - Any type
- `Traits` - Any template type accepting one type argument
