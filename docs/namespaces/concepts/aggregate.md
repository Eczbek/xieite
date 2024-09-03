# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:Aggregate\<\>
Defined in fragment [xieite:concepts.Aggregate](../../../src/concepts/aggregate.cpp)

&nbsp;

## Description
Specifies that a type is an aggregate.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type>
concept Aggregate = std::is_aggregate_v<Type>;
```

&nbsp;

## [Example](https://en.cppreference.com/w/cpp/types/is_aggregate#Example)
