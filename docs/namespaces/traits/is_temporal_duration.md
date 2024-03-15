# [xieite](../../xieite.md)\:\:[traits](../../traits.md)\:\:IsDuration
Defined in header [<xieite/traits/is_duration.hpp>](../../../include/xieite/traits/is_duration.hpp)

&nbsp;

## Description
// TODO

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename>
struct IsDuration
: std::false_type {};
```
#### 2)
```cpp
template<xieite::concepts::Arithmetic Number, std::intmax_t numerator, std::intmax_t denominator>
struct IsDuration<std::chrono::duration<Number, std::ratio<numerator, denominator>>>
: std::true_type {};
```
