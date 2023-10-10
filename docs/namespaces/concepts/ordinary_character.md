# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:OrdinaryCharacter
Defined in header [<xieite/concepts/ordinary_character.hpp>](../../../include/xieite/concepts/ordinary_character.hpp)

&nbsp;

## Description
Specifies that a type is a narrow character.

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Type>
concept OrdinaryCharacter = xieite::concepts::SameAsAny<std::remove_cv_t<Type>, char, signed char, unsigned char>;
```
