# [xieite](../xieite.md)::[concepts](../concepts.md)::NoThrowConvertibleTo
Defined in header [<xieite/concepts/NoThrowConvertibleTo.hpp>](../../include/xieite/concepts/NoThrowConvertibleTo.hpp)

<br/>

Specifies that a type can be converted to at least one of several other types without throwing an exception

<br/><br/>

## Synopsis

<br/>

```cpp
template<typename From, typename... Tos>
concept NoThrowConvertibleTo = (std::convertible_to<From, Tos> || ...);
```
### Template parameters
- `From` - Any type
- `Tos...` - Any types
