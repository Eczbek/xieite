# [xieite](../xieite.md)::[concepts](../concepts.md)::DerivedFromAny
Defined in header [<xieite/concepts/DerivedFromAny.hpp>](../../include/xieite/concepts/DerivedFromAny.hpp)

<br/>

Specifies that a type is derived from at least one of several other types

<br/><br/>

## Synopsis

<br/>

```cpp
template<typename Any, typename... Others>
concept DerivedFromAny = (std::derived_from<Any, Others> || ...);
```
### Template parameters
- `Any` - Any type
- `Others...` - Any types
