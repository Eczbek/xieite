# [xieite](../../README.md)::[concepts](../concepts.md)::NoThrowConvertibleToOneOf
Defined in header [<xieite/concepts/NoThrowConvertibleToOneOf.hpp>](../../include/xieite/concepts/NoThrowConvertibleToOneOf.hpp)

<br/>

Specifies that a type can be converted to at least one of several other types without throwing an exception

<br/><br/>

## Synopsis

<br/>

```cpp
template<typename From, typename... Tos>
concept NoThrowConvertibleToOneOf = (std::convertible_to<From, Tos> || ...);
```
### Template parameters
- `From` - Any type
- `Tos...` - Any types
