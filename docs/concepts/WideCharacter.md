# [xieite](../xieite.md)::[concepts](../concepts.md)::WideCharacter
Defined in header [<xieite/concepts/WideCharacter.hpp>](../../include/xieite/concepts/WideCharacter.hpp)

<br/>

Specifies that a type is a wide character

<br/><br/>

## Synopsis

<br/>

```cpp
template<typename Any>
concept WideCharacter = xieite::concepts::SameAs<std::remove_cv_t<Any>, wchar_t, char16_t, char32_t>;
```
### Template parameters
- `Any` - Any type
