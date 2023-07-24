# [xieite](../xieite.md)::[concepts](../concepts.md)::OrdinaryCharacter
Defined in header [<xieite/concepts/OrdinaryCharacter.hpp>](../../include/xieite/concepts/OrdinaryCharacter.hpp)

<br/>

Specifies that a type is a narrow character

<br/><br/>

## Synopsis

<br/>

```cpp
template<typename Any>
concept OrdinaryCharacter = xieite::concepts::SameAs<std::remove_cv_t<Any>, char, signed char, unsigned char>;
```
### Template parameters
- `Any` - Any type
