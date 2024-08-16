# [xieite](../../xieite.md)\:\:[traits](../../traits.md)\:\:IsSameAsAny\<\> \{\}
Defined in header [<xieite/traits/is_same_as_any.hpp>](../../../include/xieite/traits/is_same_as_any.hpp)

&nbsp;

## [Description](../concepts/same_as_any.md#Description)

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Source, typename... Targets>
struct IsSameAsAny
: std::bool_constant<xieite::concepts::SameAsAny<Source, Targets...>> {};
```

&nbsp;

## [Example](../concepts/same_as_any.md#Example)
