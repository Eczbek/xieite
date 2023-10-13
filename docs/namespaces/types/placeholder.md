# [xieite](../../xieite.md)\:\:[types](../../types.md)\:\:Placeholder
Defined in header [<xieite/types/placeholder.hpp>](../../../include/xieite/types/placeholder.hpp)

&nbsp;

## Description
A placeholder type.

&nbsp;

## Synopses
#### 1)
```cpp
struct Placeholder {
    template<typename Type>
    constexpr operator Type&() const&;

    template<typename Type>
    constexpr operator Type&&() const&&;
};
```
##### Member functions
- [operator typename](./structures/placeholder/1/operatorCast.md)
