# [xieite](../xieite.md)\:\:[algorithms](../algorithms.md)\:\:mean
Defined in header [<xieite/algorithms/mean.hpp>](../../include/xieite/algorithms/mean.hpp)

&nbsp;

## Description
Computes the mean of a set of data.

&nbsp;

## Synopses
#### 1)
```cpp
template<std::ranges::range Range>
requires(xieite::concepts::Arithmetic<std::ranges::range_value_t<Range>>)
constexpr xieite::algorithms::Result<std::ranges::range_value_t<Range>> mean(const Range& range) noexcept;
```
#### 2)
```cpp
template<xieite::concepts::Arithmetic... Arithmetics>
constexpr xieite::algorithms::Result<Arithmetics...> mean(const Arithmetics... values) noexcept;
```
