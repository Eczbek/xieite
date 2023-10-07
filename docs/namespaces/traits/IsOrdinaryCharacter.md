# [xieite](../../xieite.md)\:\:[traits](../../traits.md)\:\:IsOrdinaryCharacter
Defined in header [<xieite/traits/IsOrdinaryCharacter.hpp>](../../../include/xieite/traits/IsOrdinaryCharacter.hpp)

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Type>
struct IsOrdinaryCharacter
: std::bool_constant<xieite::concepts::OrdinaryCharacter<Type>> {};
```
