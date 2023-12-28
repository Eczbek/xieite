# [xieite](../../xieite.md)\:\:[functors](../../functors.md)\:\:staticCast
Defined in header [<xieite/functors/static_cast.hpp>](../../../include/xieite/functors/static_cast.hpp)

&nbsp;

## Synopses
#### 1)
```cpp
template<typename TypeFrom, typename TypeTo>
requires(std::convertible_to<TypeFrom, TypeTo>)
[[nodiscard]] constexpr TypeTo staticCast(const TypeFrom& value)
noexcept(xieite::concepts::NoThrowConvertibleTo<TypeFrom, TypeTo>);
```
