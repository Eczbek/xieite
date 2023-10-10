# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:OutputStream
Defined in header [<xieite/concepts/output_stream.hpp>](../../../include/xieite/concepts/output_stream.hpp)

&nbsp;

## Description
Specifies that a type is `std::ostream` or derives from it.

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Type>
concept OutputStream = std::same_as<Type, std::ostream> || std::derived_from<Type, std::ostream>;
```
