# [xieite](../xieite.md)\:\:[concepts](../concepts.md)\:\:NoThrowConvertibleTo
Defined in header [<xieite/concepts/NoThrowConvertibleTo.hpp>](../../include/xieite/concepts/NoThrowConvertibleTo.hpp)

&nbsp;

## Description
Specifies that a type can be converted to another without throwing exceptions.

&nbsp;

## Synopsis
```cpp
template<typename Source, typename Target>
concept NoThrowConvertibleTo = std::is_nothrow_convertible_v<Source, Target>;
```
