# [xieite](../../xieite.md)\:\:[traits](../../traits.md)\:\:IsSameAsAll
Defined in header [<xieite/traits/is_same_as_all.hpp>](../../../include/xieite/traits/is_same_as_all.hpp)

&nbsp;

## Description
// TODO

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Source, typename... Targets>
struct IsSameAsAll
: std::bool_constant<xieite::concepts::SameAsAll<Source, Targets...>> {};
```
