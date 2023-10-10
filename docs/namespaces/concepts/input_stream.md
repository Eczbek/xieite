# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:InputStream
Defined in header [<xieite/concepts/input_stream.hpp>](../../../include/xieite/concepts/input_stream.hpp)

&nbsp;

## Description
Specifies that a type is `std::istream` or derives from it.

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Type>
concept InputStream = std::same_as<Type, std::istream> || std::derived_from<Type, std::istream>;
```
