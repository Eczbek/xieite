# [xieite](../xieite.md)::[concepts](../concepts.md)::Character
Defined in header [<xieite/concepts/Character.hpp>](../../include/xieite/concepts/Character.hpp)

<br/>

Specifies that a type is a character

<br/><br/>

## Synopsis

<br/>

```cpp
template<typename Any>
concept Character = xieite::concepts::WideCharacter<Any> || xieite::concepts::SameAsAny<std::remove_cv_t<Any>, char, char8_t>;
```
### Template parameters
- `Any` - Any type
