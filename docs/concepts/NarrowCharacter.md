# [xieite](../xieite.md)::[concepts](../concepts.md)::NarrowCharacter
Defined in header [<xieite/concepts/NarrowCharacter.hpp>](../../include/xieite/concepts/NarrowCharacter.hpp)

<br/>

Specifies that a type is a narrow character

<br/><br/>

## Synopsis

<br/>

```cpp
template<typename Any>
concept NarrowCharacter = xieite::concepts::OrdinaryCharacter<Any> || std::same_as<std::remove_cv_t<Any>, char8_t>;
```
### Template parameters
- `Any` - Any type
