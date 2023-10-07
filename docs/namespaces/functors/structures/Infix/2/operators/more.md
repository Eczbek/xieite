# [xieite](../../../../../../xieite.md)\:\:[functors](../../../../../../functors.md)\:\:[Infix\<callback\>](../../../../Infix.md)\:\:operator\<
Defined in header [<xieite/functors/Infix.hpp>](../../../../../../../include/xieite/functors/Infix.hpp)

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Argument>
requires(std::invocable<decltype(callback), const Argument&>)
friend constexpr std::invoke_result_t<decltype(callback), const Argument&> operator>(xieite::functors::Infix<callback>, const Argument& argument);
```
#### 2)
```cpp
friend constexpr std::invoke_result_t<decltype(callback), Argument&> operator>(xieite::functors::Infix<callback>, Argument& argument);
```
