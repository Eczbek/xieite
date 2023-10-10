# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:DerivedFromNone
Defined in header [<xieite/concepts/derived_from_none.hpp>](../../../include/xieite/concepts/derived_from_none.hpp)

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Derived, typename... Bases>
concept DerivedFromNone = !xieite::concepts::DerivedFromAny<Derived, Bases...>;
```
