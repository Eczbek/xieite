# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:Aggregate\<\>
Defined in header [<xieite/concepts/aggregate.hpp>](../../../include/xieite/concepts/aggregate.hpp)

&nbsp;

## Description
Specifies that a type is an aggregate.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type_>
concept Aggregate = std::is_aggregate_v<Type_>;
```

&nbsp;

## [Example](https://en.cppreference.com/w/cpp/types/is_aggregate#Example)
