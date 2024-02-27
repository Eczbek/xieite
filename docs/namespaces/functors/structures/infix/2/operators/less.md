# [xieite](../../../../../../xieite.md)\:\:[functors](../../../../../../functors.md)\:\:[Infix<Functor>](../../../../infix.md)\:\:operator<
Defined in header [<xieite/functors/infix.hpp>](../../../../../../../include/xieite/functors/infix.hpp)

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Argument>
requires(std::invocable<Functor, Argument&&>)
friend constexpr std::invoke_result_t<Functor, Argument&&> operator<(Argument&& argument, const xieite::functors::Infix<Functor>& infix)
noexcept(xieite::concepts::NoThrowInvocable<Functor, Argument&&>);
```
