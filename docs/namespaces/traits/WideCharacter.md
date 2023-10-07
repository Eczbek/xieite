# [xieite](../../xieite.md)\:\:[traits](../../traits.md)\:\:IsWideCharacter
Defined in header [<xieite/traits/IsWideCharacter.hpp>](../../../include/xieite/traits/IsWideCharacter.hpp)

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Type>
struct IsWideCharacter
: std::bool_constant<xieite::concepts::WideCharacter<Type>> {};
```
