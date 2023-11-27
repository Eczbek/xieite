# [xieite](../../../../../../xieite.md)\:\:[functors](../../../../../../functors.md)\:\:[Constant<Type>](../../../../constant.md)\:\:Constant
Defined in header [<xieite/functors/constant.hpp>](../../../../../../../include/xieite/functors/constant.hpp)

&nbsp;

## Synopses
#### 1)
```cpp
template<typename... Arguments>
constexpr Constant(Arguments&&... arguments)
noexcept(noexcept(Type(std::forward<Arguments>(arguments)...)));
```
