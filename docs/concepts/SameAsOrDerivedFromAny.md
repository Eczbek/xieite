# [xieite](../xieite.md)::[concepts](../concepts.md)::SameAsOrDerivedFromAnyAny
Defined in header [<xieite/concepts/SameAsOrDerivedFromAnyAny.hpp>](../../include/xieite/concepts/SameAsOrDerivedFromAnyAny.hpp)

<br/>

Specifies that a type is derived from at least one of several other types

<br/><br/>

## Synopsis

<br/>

```cpp
template<typename Any, typename... Others>
concept SameAsOrDerivedFromAnyAny = xieite::concepts::SameAsAny<Any, Others...> || xieite::concepts::DerivedFromAny<Any, Others...>;
```
### Template parameters
- `Any` - Any type
- `Others...` - Any types
