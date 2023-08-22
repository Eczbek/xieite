# [xieite](../xieite.md)\:\:[algorithms](../algorithms.md)\:\:median
Defined in header [<xieite/algorithms/median.hpp>](../../include/xieite/algorithms/median.hpp)

&nbsp;

## Description
Computes the median of a set of data.

&nbsp;

## Synopses
#### 1)
```cpp
template<std::ranges::range Range>
requires(xieite::concepts::Arithmetic<std::ranges::range_value_t<Range>>)
constexpr xieite::algorithms::Result<std::ranges::range_value_t<Range>> median(const Range& range) noexcept;
```
#### 2)
```cpp
template<xieite::concepts::Arithmetic... Arithmetics>
constexpr xieite::algorithms::Result<Arithmetics...> median(const Arithmetics... values) noexcept;
```
