# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:Numeric
Defined in header [<xieite/concepts/numeric.hpp>](../../../include/xieite/concepts/numeric.hpp)

&nbsp;

## Description
Specifies that a type is arithmetic but not boolean.

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Type>
concept Numeric = xieite::concepts::Arithmetic<Type> && !std::same_as<Type, bool>;
```
