# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:NoThrowConvertibleToAllOf
Defined in header [<xieite/concepts/no_throw_convertible_to_all_of.hpp>](../../../include/xieite/concepts/no_throw_convertible_to_all_of.hpp)

&nbsp;

## Description
Specifies that a type can be converted to several other types without throwing exceptions.

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Source, typename... Targets>
concept NoThrowConvertibleToAllOf = (... && xieite::concepts::NoThrowConvertibleTo<Source, Targets>);
```
