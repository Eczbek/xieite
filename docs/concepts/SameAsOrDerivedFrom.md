# [xieite](../xieite.md)::[concepts](../concepts.md)::SameAsOrDerivedFrom
Defined in header [<xieite/concepts/SameAsOrDerivedFrom.hpp>](../../include/xieite/concepts/SameAsOrDerivedFrom.hpp)

<br/>

Specifies that a type is derived from at least one of several other types

<br/><br/>

## Synopsis

<br/>

```cpp
template<typename Any, typename... Others>
concept SameAsOrDerivedFrom = xieite::concepts::SameAs<Any, Others...> || xieite::concepts::DerivedFrom<Any, Others...>;
```
### Template parameters
- `Any` - Any type
- `Others...` - Any types
