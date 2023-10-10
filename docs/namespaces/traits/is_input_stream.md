# [xieite](../../xieite.md)\:\:[traits](../../traits.md)\:\:IsInputStream
Defined in header [<xieite/traits/is_input_stream.hpp>](../../../include/xieite/traits/is_input_stream.hpp)

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Type>
struct IsInputStream
: std::bool_constant<xieite::concepts::InputStream<Type>> {};
```
