# [xieite](../../../../../../xieite.md)\:\:[functors](../../../../../../functors.md)\:\:[AggregateInitialize<Target>](../../../../aggregate_initialize.md)\:\:operator\(\)\<\>\(\)
Defined in header [<xieite/functors/aggregate_initialize.hpp>](../../../../../../../include/xieite/functors/aggregate_initialize.hpp)

&nbsp;

## Description
Aggregate-initializes `Type` with `Arguments...`.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename... Arguments>
requires(xieite::concepts::AggregateInitializable<Type, Arguments...>)
[[nodiscard]] constexpr Type operator()(Arguments&&... arguments) const
noexcept(xieite::concepts::NoThrowAggregateInitializable<Type, Arguments...>);
```

&nbsp;

## [Example](../../../../aggregate_initialize.md#Example)
