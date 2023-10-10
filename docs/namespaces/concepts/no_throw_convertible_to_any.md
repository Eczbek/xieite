# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:NoThrowConvertibleToAny
Defined in header [<xieite/concepts/no_throw_convertible_to_any.hpp>](../../../include/xieite/concepts/no_throw_convertible_to_any.hpp)

&nbsp;

## Description
Specifies that a type can be converted to at least one of several other types without throwing exceptions.

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Source, typename... Targets>
concept NoThrowConvertibleToAny = (... || xieite::concepts::NoThrowConvertibleTo<Source, Targets>);
```
