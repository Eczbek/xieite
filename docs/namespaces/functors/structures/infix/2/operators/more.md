# [xieite](../../../../../../xieite.md)\:\:[functors](../../../../../../functors.md)\:\:[Infix<Functor>](../../../../infix.md)\:\:operator<
Defined in header [<xieite/functors/infix.hpp>](../../../../../../../include/xieite/functors/infix.hpp)

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Argument>
requires(std::invocable<Functor, Argument&&>)
friend constexpr std::invoke_result_t<Functor, Argument&&> operator>(const xieite::functors::Infix<Functor>& infix, Argument&& argument);
```
