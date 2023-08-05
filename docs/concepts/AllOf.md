# [xieite](../xieite.md)::[concepts](../concepts.md)::AllOf
Defined in header [<xieite/concepts/AllOf.hpp>](../../include/xieite/concepts/AllOf.hpp)

<br/>

Specifies that a type satisfies all of several type traits

<br/><br/>

## Synopsis

<br/>

```cpp
template<typename Type, template<typename> typename... Traits>
concept AllOf = xieite::traits::IsAllOf<Type, Traits...>::value;
```
### Template parameters
- `Type` - Any type
- `Traits` - Any template type accepting one type argument
