# [xieite](../xieite.md)\:\:[types](../types.md)\:\:Placeholder
Defined in header [<xieite/types/Placeholder.hpp>](../../include/xieite/types/Placeholder.hpp)

&nbsp;

## Description
A placeholder type.

&nbsp;

## Synopses
#### 1)
```cpp
struct Placeholder {
    template<typename Type>
    constexpr operator Type&() const noexcept;

    template<typename Type>
    constexpr operator Type&&() const noexcept;
};
```
