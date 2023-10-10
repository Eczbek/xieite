# [xieite](../../xieite.md)\:\:[traits](../../traits.md)\:\:DerivedFrom
Defined in header [<xieite/traits/derived_from.hpp>](../../../include/xieite/traits/derived_from.hpp)

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Derived, typename Base>
struct DerivedFrom
: std::bool_constant<std::derived_from<Derived, Base>> {};
```
