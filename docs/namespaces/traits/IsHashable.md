# [xieite](../../xieite.md)\:\:[traits](../../traits.md)\:\:IsHashable
Defined in header [<xieite/traits/IsHashable.hpp>](../../../include/xieite/traits/IsHashable.hpp)

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Type>
struct IsHashable
: std::bool_constant<xieite::concepts::Hashable<Type>> {};
```
