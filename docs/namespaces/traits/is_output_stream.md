# [xieite](../../xieite.md)\:\:[traits](../../traits.md)\:\:IsOutputStream
Defined in header [<xieite/traits/is_output_stream.hpp>](../../../include/xieite/traits/is_output_stream.hpp)

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type>
struct IsOutputStream
: std::bool_constant<xieite::concepts::OutputStream<Type>> {};
```
