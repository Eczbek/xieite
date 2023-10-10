# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:WideCharacter
Defined in header [<xieite/concepts/wide_character.hpp>](../../../include/xieite/concepts/wide_character.hpp)

&nbsp;

## Description
Specifies that a type is a wide character.

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Type>
concept WideCharacter = xieite::concepts::SameAsAny<std::remove_cv_t<Type>, wchar_t, char16_t, char32_t>;
```
