# [xieite](../xieite.md)\:\:[concepts](../concepts.md)\:\:NarrowCharacter
Defined in header [<xieite/concepts/NarrowCharacter.hpp>](../../include/xieite/concepts/NarrowCharacter.hpp)

&nbsp;

## Description
Specifies that a type is a narrow character.

&nbsp;

## Synopsis
```cpp
template<typename Type>
concept NarrowCharacter = xieite::concepts::OrdinaryCharacter<Type> || std::same_as<std::remove_cv_t<Type>, char8_t>;
```
