# [xieite](../../xieite.md)\:\:[traits](../../traits.md)\:\:TemporalDuration
Defined in header [<xieite/traits/temporal_duration.hpp>](../../../include/xieite/traits/temporal_duration.hpp)

&nbsp;

## Synopses
#### 1)
```cpp
template<typename>
struct TemporalDuration
: std::false_type {};
```
#### 2)
```cpp
template<xieite::concepts::Numeric Number, std::intmax_t numerator, std::intmax_t denominator>
struct TemporalDuration<std::chrono::duration<Number, std::ratio<numerator, denominator>>>
: std::true_type {};
```
