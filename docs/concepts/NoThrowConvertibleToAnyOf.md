# [xieite](../xieite.md)\:\:[concepts](../concepts.md)\:\:NoThrowConvertibleToAnyOf
Defined in header [<xieite/concepts/NoThrowConvertibleToAnyOf.hpp>](../../include/xieite/concepts/NoThrowConvertibleToAnyOf.hpp)

&nbsp;

## Description
Specifies that a type can be converted to at least one of several other types without throwing exceptions.

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Source, typename... Targets>
concept NoThrowConvertibleToAnyOf = (xieite::concepts::NoThrowConvertibleTo<Source, Targets> || ...);
```
