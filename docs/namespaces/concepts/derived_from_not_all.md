# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:DerivedFromNotAll
Defined in header [<xieite/concepts/derived_from_not_all.hpp>](../../../include/xieite/concepts/derived_from_not_all.hpp)

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Derived, typename... Bases>
concept DerivedFromNotAll = !xieite::concepts::DerivedFromAll<Derived, Bases...>;
```
