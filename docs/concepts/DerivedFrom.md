# [xieite](../xieite.md)::[concepts](../concepts.md)::DerivedFrom
Defined in header [<xieite/concepts/DerivedFrom.hpp>](../../include/xieite/concepts/DerivedFrom.hpp)

<br/>

Specifies that a type is derived from at least one of several other types

<br/><br/>

## Synopsis

<br/>

```cpp
template<typename Any, typename... Others>
concept DerivedFrom = (std::derived_from<Any, Others> || ...);
```
### Template parameters
- `Any` - Any type
- `Others...` - Any types
