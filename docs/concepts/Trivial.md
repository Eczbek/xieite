# [xieite](../xieite.md)\:\:[concepts](../concepts.md)\:\:Trivial
Defined in header [<xieite/concepts/Trivial.hpp>](../../include/xieite/concepts/Trivial.hpp)

&nbsp;

## Description
Specifies that a type is trivial.

&nbsp;

## Synopsis
```cpp
template<typename Type>
concept Trivial = std::is_trivial_v<Type>;
```
