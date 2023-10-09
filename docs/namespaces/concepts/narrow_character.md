# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:NarrowCharacter
Defined in header [<xieite/concepts/narrow_character.hpp>](../../../include/xieite/concepts/narrow_character.hpp)

&nbsp;

## Description
Specifies that a type is a narrow character.

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Type>
concept NarrowCharacter = xieite::concepts::OrdinaryCharacter<Type> || std::same_as<std::remove_cv_t<Type>, char8_t>;
```
