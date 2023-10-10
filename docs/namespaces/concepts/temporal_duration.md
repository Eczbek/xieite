# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:TemporalDuration
Defined in header [<xieite/concepts/temporal_duration.hpp>](../../../include/xieite/concepts/temporal_duration.hpp)

&nbsp;

## Description
Specifies that a type is a `std::chrono::duration`.

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Type>
concept TemporalDuration = xieite::traits::TemporalDuration<Type>::value;
```
