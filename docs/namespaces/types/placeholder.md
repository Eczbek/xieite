# [xieite](../../xieite.md)\:\:[types](../../types.md)\:\:Placeholder \{\}
Defined in header [<xieite/types/placeholder.hpp>](../../../include/xieite/types/placeholder.hpp)

&nbsp;

## Description
A placeholder type.

&nbsp;

## Synopsis
#### 1)
```cpp
struct Placeholder {
    template<typename... Arguments_>
    constexpr Placeholder(Arguments_&&...) noexcept;

    template<typename Type_>
    constexpr operator Type_&() const & noexcept;

    template<typename Type_>
    constexpr operator Type_&&() const && noexcept;
};
```
- Placeholder\<\>()
- operator typename\<\>()

&nbsp;

## [Example](../../../include/xieite/concepts/invocable_with_argument_count.hpp)
