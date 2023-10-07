# [xieite](../../xieite.md)\:\:[traits](../../traits.md)\:\:IsStreamableOut
Defined in header [<xieite/traits/IsStreamableOut.hpp>](../../../include/xieite/traits/IsStreamableOut.hpp)

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Type>
struct IsStreamableOut
: std::bool_constant<xieite::concepts::StreamableOut<Type>> {};
```
