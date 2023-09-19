# [xieite](../../../../xieite.md)\:\:[functors](../../../../functors.md)\:\:[Infix\<callback\>](../../../Infix.md)\:\:operator\<
Defined in header [<xieite/functors/Infix.hpp>](../../../../../include/xieite/functors/Infix.hpp)

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Argument>
requires(std::invocable<decltype(callback), const Argument&>)
constexpr std::invoke_result_t<decltype(callback), const Argument&> operator>(const Argument& argument) const;
```
#### 2)
```cpp
template<typename Argument>
requires(std::invocable<decltype(callback), Argument&>)
constexpr std::invoke_result_t<decltype(callback), Argument&> operator>(Argument& argument) const;
```
