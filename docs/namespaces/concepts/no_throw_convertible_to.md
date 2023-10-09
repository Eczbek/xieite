# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:NoThrowConvertibleTo
Defined in header [<xieite/concepts/no_throw_convertible_to.hpp>](../../../include/xieite/concepts/no_throw_convertible_to.hpp)

&nbsp;

## Description
Specifies that a type can be converted to another without throwing exceptions.

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Source, typename Target>
concept NoThrowConvertibleTo = std::is_nothrow_convertible_v<Source, Target>;
```
