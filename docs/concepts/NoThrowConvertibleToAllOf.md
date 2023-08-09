# [xieite](../xieite.md)\:\:[concepts](../concepts.md)\:\:NoThrowConvertibleToAllOf
Defined in header [<xieite/concepts/NoThrowConvertibleToAllOf.hpp>](../../include/xieite/concepts/NoThrowConvertibleToAllOf.hpp)

&nbsp;

## Description
Specifies that a type can be converted to several other types without throwing exceptions.

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Source, typename... Targets>
concept NoThrowConvertibleToAllOf = (xieite::concepts::NoThrowConvertibleTo<Source, Targets> && ...);
```
