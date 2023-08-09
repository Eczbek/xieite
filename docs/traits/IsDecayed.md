# [xieite](../xieite.md)\:\:[traits](../traits.md)\:\:IsDecayed
Defined in header [<xieite/traits/IsDecayed.hpp>](../../include/xieite/traits/IsDecayed.hpp)

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Type>
struct IsDecayed
: std::bool_constant<xieite::concepts::Decayed<Type>> {};
```
