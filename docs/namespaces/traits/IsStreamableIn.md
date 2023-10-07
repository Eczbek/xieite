# [xieite](../../xieite.md)\:\:[traits](../../traits.md)\:\:IsStreamableIn
Defined in header [<xieite/traits/IsStreamableIn.hpp>](../../../include/xieite/traits/IsStreamableIn.hpp)

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Type>
struct IsStreamableIn
: std::bool_constant<xieite::concepts::StreamableIn<Type>> {};
```
