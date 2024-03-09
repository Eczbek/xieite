# [xieite](../../../../../../xieite.md)\:\:[functors](../../../../../../functors.md)\:\:[StaticCast<Target>](../../../../static_cast.md)\:\:operator\(\)
Defined in header [<xieite/functors/static_cast.hpp>](../../../../../../../include/xieite/functors/static_cast.hpp)

&nbsp;

## Description
Casts a value to the `Target` type.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::convertible_to<Target> Source>
constexpr Target operator()(Source&& value) const
noexcept(xieite::concepts::NoThrowConvertibleTo<Source, Target>);
```

&nbsp;

## [Example](../../../../static_cast.md#Example)
