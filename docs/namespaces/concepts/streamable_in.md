# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:StreamableIn
Defined in header [<xieite/concepts/streamable_in.hpp>](../../../include/xieite/concepts/streamable_in.hpp)

&nbsp;

## Description
Specifies that a type can be streamed into.

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Type>
concept StreamableIn = requires(Type value, std::istream inputStream) {
    { inputStream >> value } -> std::same_as<std::istream&>;
};
```
