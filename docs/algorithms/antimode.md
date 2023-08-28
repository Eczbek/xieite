# [xieite](../xieite.md)\:\:[algorithms](../algorithms.md)\:\:antimode
Defined in header [<xieite/algorithms/antimode.hpp>](../../include/xieite/algorithms/antimode.hpp)

&nbsp;

## Description
Computes the antimode of a set of data.

&nbsp;

## Synopses
#### 1)
```cpp
template<std::ranges::range Range>
requires(xieite::concepts::Numeric<std::ranges::range_value_t<Range>>)
constexpr xieite::algorithms::Result<std::ranges::range_value_t<Range>> antimode(const Range& range) noexcept;
```
#### 2)
```cpp
template<xieite::concepts::Numeric... Numbers>
constexpr xieite::algorithms::Result<Numbers...> antimode(const Numbers... values) noexcept;
```
