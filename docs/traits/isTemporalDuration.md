# xieite::traits::isTemporalDuration
Defined in header `<xieite/traits/isTemporalDuration.hpp>`

<br/>

A boolean representing whether types `R`, `N`, and `D` create a valid `std::chrono::duration`.

<br/><br/>

## Declarations
```cpp
template<typename>
constexpr bool isTemporalDuration = false;
```
```cpp
template<xieite::concepts::Arithmetic Number, std::intmax_t numerator, std::intmax_t denominator>
constexpr bool isTemporalDuration<std::chrono::duration<Number, std::ratio<numerator, denominator>>> = true;
```
