# [xieite](../xieite.md)\:\:[traits](../traits.md)\:\:IsDerivedFrom
Defined in header [<xieite/traits/IsDerivedFrom.hpp>](../../include/xieite/traits/IsDerivedFrom.hpp)

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Derived, typename Base>
struct IsDerivedFrom
: std::bool_constant<std::derived_from<Derived, Base>> {};
```
