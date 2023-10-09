# [xieite](../../xieite.md)\:\:[traits](../../traits.md)\:\:IsHasher
Defined in header [<xieite/traits/is_hasher.hpp>](../../../include/xieite/traits/is_hasher.hpp)

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Type, typename Argument>
struct IsHasher
: std::bool_constant<xieite::concepts::Hasher<Type, Argument>> {};
```
