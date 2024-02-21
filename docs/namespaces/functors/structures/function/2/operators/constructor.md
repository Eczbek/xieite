# [xieite](../../../../../../xieite.md)\:\:[functors](../../../../../../functors.md)\:\:[Function<Result(Arguments...)>](../../../../function.md)\:\:Function
Defined in header [<xieite/functors/function.hpp"](../../../../../../../include/xieite/functors/function.hpp)

&nbsp;

## Synopses
#### 1)
```cpp
constexpr Function() noexcept;
```
#### 2)
```cpp
template<xieite::concepts::Functable<Result(Arguments...)> Functor>
constexpr Function(const Functor& functor) noexcept;
```
