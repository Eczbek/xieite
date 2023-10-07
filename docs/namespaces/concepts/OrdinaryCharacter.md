# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:OrdinaryCharacter
Defined in header [<xieite/concepts/OrdinaryCharacter.hpp>](../../../include/xieite/concepts/OrdinaryCharacter.hpp)

&nbsp;

## Description
Specifies that a type is a narrow character.

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Type>
concept OrdinaryCharacter = xieite::concepts::SameAsAnyOf<std::remove_cv_t<Type>, char, signed char, unsigned char>;
```
