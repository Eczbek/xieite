# [xieite](../xieite.md)\:\:[traits](../traits.md)\:\:IsChronoDuration
Defined in header [<xieite/traits/IsChronoDuration.hpp>](../../include/xieite/traits/IsChronoDuration.hpp)

&nbsp;

## Synopses
#### 1)
```cpp
template<typename>
struct IsChronoDuration
: std::false_type {};
```
#### 2)
```cpp
template<xieite::concepts::Numeric Number, std::intmax_t numerator, std::intmax_t denominator>
struct IsChronoDuration<std::chrono::duration<Number, std::ratio<numerator, denominator>>>
: std::true_type {};
```
