# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:Derivable
Defined in header [<xieite/concepts/derivable.hpp>](../../../include/xieite/concepts/derivable.hpp)

&nbsp;

## Description
Specifies that a type can be derived from.

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Type>
concept Derivable = std::is_class_v<Type> && !std::is_final_v<Type>;
```
