# [xieite](../xieite.md)\:\:[concepts](../concepts.md)\:\:Numeric
Defined in header [<xieite/concepts/Numeric.hpp>](../../include/xieite/concepts/Numeric.hpp)

&nbsp;

## Description
Specifies that a type is a arithmetic but not a boolean.

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Type>
concept Numeric = !std::same_as<Type, bool> && xieite::concepts::Arithmetic<Type>;
```
