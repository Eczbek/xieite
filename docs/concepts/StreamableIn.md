# [xieite](../xieite.md)\:\:[concepts](../concepts.md)\:\:StreamableIn
Defined in header [<xieite/concepts/StreamableIn.hpp>](../../include/xieite/concepts/StreamableIn.hpp)

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
