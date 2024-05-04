# [xieite](../../../../../../xieite.md)\:\:[functors](../../../../../../functors.md)\:\:[StaticCast<Target_>](../../../../static_cast.md)\:\:operator\(\)\<\>\(\)
Defined in header [<xieite/functors/static_cast.hpp>](../../../../../../../include/xieite/functors/static_cast.hpp)

&nbsp;

## Description
Casts a value to the `Target` type.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::convertible_to<Target_> Source_>
constexpr Target_ operator()(Source_&& value) const
noexcept(xieite::concepts::NoThrowConvertibleTo<Source_, Target_>);
```

&nbsp;

## [Example](../../../../static_cast.md#Example)
