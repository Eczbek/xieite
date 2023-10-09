# [xieite](../../xieite.md)\:\:[traits](../../traits.md)\:\:IsHashable
Defined in header [<xieite/traits/is_hashable.hpp>](../../../include/xieite/traits/is_hashable.hpp)

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Type>
struct IsHashable
: std::bool_constant<xieite::concepts::Hashable<Type>> {};
```
