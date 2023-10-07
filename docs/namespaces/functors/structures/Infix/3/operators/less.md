# [xieite](../../../../../../xieite.md)\:\:[functors](../../../../../../functors.md)\:\:[Infix\<callback\>](../../../../Infix.md)\:\:operator\<
Defined in header [<xieite/functors/Infix.hpp>](../../../../../../../include/xieite/functors/Infix.hpp)

&nbsp;

## Synopses
#### 1)
```cpp
template<typename LeftArgument>
requires(std::invocable<decltype(callback), const LeftArgument&, xieite::types::Placeholder>)
[[nodiscard]] friend constexpr Infix<callback>::Intermediate<const LeftArgument&> operator<(const LeftArgument& leftArgument, xieite::functors::Infix<callback>) noexcept;
```
#### 2)
```cpp
template<typename LeftArgument>
requires(std::invocable<decltype(callback), LeftArgument&, xieite::types::Placeholder>)
[[nodiscard]] friend constexpr Infix<callback>::Intermediate<LeftArgument&> operator<(LeftArgument& leftArgument, xieite::functors::Infix<callback>) noexcept;
```
