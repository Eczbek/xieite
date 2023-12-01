# [xieite](../../xieite.md)\:\:[traits](../../traits.md)\:\:IsWideCharacter
Defined in header [<xieite/traits/is_wide_character.hpp>](../../../include/xieite/traits/is_wide_character.hpp)

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Type>
struct IsWideCharacter
: std::bool_constant<xieite::concepts::WideCharacter<Type>> {};
```
