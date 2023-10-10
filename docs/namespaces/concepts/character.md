# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:Character
Defined in header [<xieite/concepts/character.hpp>](../../../include/xieite/concepts/character.hpp)

&nbsp;

## Description
Specifies that a type is a character.

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Type>
concept Character = xieite::concepts::WideCharacter<Type> || xieite::concepts::SameAsAny<std::remove_cv_t<Type>, char, char8_t>;
```
