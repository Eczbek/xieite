# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:Decayed
Defined in header [<xieite/concepts/Decayed.hpp>](../../../include/xieite/concepts/Decayed.hpp)

&nbsp;

## Description
Specifies that a type is decayed.

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Type>
concept Decayed = std::same_as<Type, std::decay_t<Type>>;
```
