# [xieite](../../xieite.md)\:\:[traits](../../traits.md)\:\:IsStreamableOut
Defined in header [<xieite/traits/is_streamable_out.hpp>](../../../include/xieite/traits/is_streamable_out.hpp)

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Type>
struct IsStreamableOut
: std::bool_constant<xieite::concepts::StreamableOut<Type>> {};
```
