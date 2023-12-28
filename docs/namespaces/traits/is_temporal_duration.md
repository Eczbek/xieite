# [xieite](../../xieite.md)\:\:[traits](../../traits.md)\:\:IsTemporalDuration
Defined in header [<xieite/traits/is_temporal_duration.hpp>](../../../include/xieite/traits/is_temporal_duration.hpp)

&nbsp;

## Synopses
#### 1)
```cpp
template<typename>
struct IsTemporalDuration
: std::false_type {};
```
#### 2)
```cpp
template<xieite::concepts::Arithmetic Number, std::intmax_t numerator, std::intmax_t denominator>
struct IsTemporalDuration<std::chrono::duration<Number, std::ratio<numerator, denominator>>>
: std::true_type {};
```
