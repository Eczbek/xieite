# [xieite](../../xieite.md)\:\:[types](../../types.md)\:\:CollapseReference\<\>
Defined in header [<xieite/types/collapse_reference.hpp>](../../../include/xieite/types/collapse_reference.hpp)

&nbsp;

## Description
"Collapses" a reference.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type_, typename Other_>
using CollapseReference = std::conditional_t<std::is_lvalue_reference_v<Other_>, std::conditional_t<std::is_const_v<Other_>, std::add_const_t<std::add_lvalue_reference_t<Type_>>, std::add_lvalue_reference_t<Type_>>, std::add_rvalue_reference_t<Type_>>;
```

&nbsp;

## [Example](https://en.cppreference.com/w/cpp/language/reference#Reference_collapsing)
