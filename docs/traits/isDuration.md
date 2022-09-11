# gcufl::traits::isDuration
Declared in `<gcufl/traits/isDuration.hpp>`
```cpp
template <typename>
constexpr bool isDuration = false;

template <gcufl::concepts::Arithmetic R, std::intmax_t N, std::intmax_t D>
constexpr bool isDuration<std::chrono::duration<R, std::ratio<N, D>>> = true;
```
Checks whether some types `R`, `N`, and `D` create a valid `std::chrono::duration`.
