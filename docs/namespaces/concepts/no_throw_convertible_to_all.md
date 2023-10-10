# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:NoThrowConvertibleToAll
Defined in header [<xieite/concepts/no_throw_convertible_to_all.hpp>](../../../include/xieite/concepts/no_throw_convertible_to_all.hpp)

&nbsp;

## Description
Specifies that a type can be converted to several other types without throwing exceptions.

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Source, typename... Targets>
concept NoThrowConvertibleToAll = (... && xieite::concepts::NoThrowConvertibleTo<Source, Targets>);
```
