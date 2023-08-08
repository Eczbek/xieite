# [xieite](../xieite.md)\:\:[concepts](../concepts.md)\:\:Polymorphic
Defined in header [<xieite/concepts/Polymorphic.hpp>](../../include/xieite/concepts/Polymorphic.hpp)

&nbsp;

## Description
Specifies that a type is polymorphic.

&nbsp;

## Synopsis
```cpp
template<typename Type>
concept Polymorphic = std::is_polymorphic_v<Type>;
```
