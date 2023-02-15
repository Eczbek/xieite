# xieite::traits::isTemporalDuration
Declared in `<xieite/traits/isTemporalDuration.hpp>`

<br/>

A boolean representing whether types `R`, `N`, and `D` create a valid `std::chrono::duration`.

<br/><br/>

## Definitions
```cpp
template<typename>
constexpr bool isTemporalDuration = false;
```
```cpp
template<xieite::concepts::Arithmetic R, std::intmax_t N, std::intmax_t D>
constexpr bool isTemporalDuration<std::chrono::duration<R, std::ratio<N, D>>> = true;
```
