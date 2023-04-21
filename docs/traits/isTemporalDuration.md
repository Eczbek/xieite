# [`xieite`](../../README.md)`::`[`traits`](../../docs/traits.md)`::isTemporalDuration`
Defined in header [`<xieite/traits/isTemporalDuration.hpp>`](../../include/xieite/traits/isTemporalDuration.hpp)

<br/>

A boolean representing whether an arithmetic type and two `std::intmax_t` values can create a `std::chrono::duration`.

<br/><br/>

## Synopses

<br/>

```cpp
template<typename>
constexpr bool isTemporalDuration = false;
```
### Template parameters
- Unconstrained parameter

<br/>

```cpp
template<xieite::concepts::Arithmetic Number, std::intmax_t numerator, std::intmax_t denominator>
constexpr bool isTemporalDuration<std::chrono::duration<Number, std::ratio<numerator, denominator>>> = true;
```
### Template parameters
- `Number` - An arithmetic type, satisfying `xieite::concepts::Arithmetic`
- `numerator` - A `std::intmax_t` copy
- `denominator` - Another `std::int_max_t` copy

<br/><br/>

## See also
- [`xieite::concepts::Arithmetic`](../../docs/concepts/Arithmetic.md)
