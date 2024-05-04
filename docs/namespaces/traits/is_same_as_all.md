# [xieite](../../xieite.md)\:\:[traits](../../traits.md)\:\:IsSameAsAll\<\> \{\}
Defined in header [<xieite/traits/is_same_as_all.hpp>](../../../include/xieite/traits/is_same_as_all.hpp)

&nbsp;

## [Description](../concepts/same_as_all.md#Description)

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Source_, typename... Targets_>
struct IsSameAsAll
: std::bool_constant<xieite::concepts::SameAsAll<Source_, Targets_...>> {};
```

&nbsp;

## [Example](../concepts/same_as_all.md#Example)
