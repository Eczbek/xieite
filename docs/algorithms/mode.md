# [xieite](../xieite.md)\:\:[algorithms](../algorithms.md)\:\:mode
Defined in header [<xieite/algorithms/mode.hpp>](../../include/xieite/algorithms/mode.hpp)

&nbsp;

## Description
Computes the mode of a set of data.

&nbsp;

## Synopses
#### 1)
```cpp
template<std::ranges::range Range>
requires(xieite::concepts::Numeric<std::ranges::range_value_t<Range>>)
constexpr xieite::algorithms::Result<std::ranges::range_value_t<Range>> mode(const Range& range) noexcept;
```
#### 2)
```cpp
template<xieite::concepts::Numeric... Numbers>
constexpr xieite::algorithms::Result<Numbers...> mode(const Numbers... values) noexcept;
```
