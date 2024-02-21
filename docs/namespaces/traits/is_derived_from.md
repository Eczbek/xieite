# [xieite](../../xieite.md)\:\:[traits](../../traits.md)\:\:IsDerivedFrom
Defined in header [<xieite/traits/is_derived_from.hpp"](../../../include/xieite/traits/is_derived_from.hpp)

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Derived, typename Base>
struct IsDerivedFrom
: std::bool_constant<std::derived_from<Derived, Base>> {};
```
