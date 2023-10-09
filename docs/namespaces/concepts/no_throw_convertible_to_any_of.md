# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:NoThrowConvertibleToAnyOf
Defined in header [<xieite/concepts/no_throw_convertible_to_any_of.hpp>](../../../include/xieite/concepts/no_throw_convertible_to_any_of.hpp)

&nbsp;

## Description
Specifies that a type can be converted to at least one of several other types without throwing exceptions.

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Source, typename... Targets>
concept NoThrowConvertibleToAnyOf = (... || xieite::concepts::NoThrowConvertibleTo<Source, Targets>);
```
