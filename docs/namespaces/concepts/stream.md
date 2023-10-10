# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:Stream
Defined in header [<xieite/concepts/output_stream.hpp>](../../../include/xieite/concepts/output_stream.hpp)

&nbsp;

## Description
Specifies that a type is or derives from `std::istream` or `std::ostream`

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Type>
concept Stream = xieite::concepts::InputStream<Type> || xieite::concepts::OutputStream<Type>;
```
