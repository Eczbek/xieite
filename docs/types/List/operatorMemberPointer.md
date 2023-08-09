# [xieite](../../xieite.md)\:\:[types](../../types.md)\:\:[List\<Types...\>](../List.md)\:\:operator-\>*
Defined in header [<xieite/types/List.hpp>](../../../include/xieite/types/List.hpp)

&nbsp;

## Description
For use in `xieite::types::Unique`.

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Type>
constexpr std::conditional_t<(std::is_same_v<Types, Type> || ...), xieite::types::List<Types...>, xieite::types::List<Types..., Type>> operator->*(const xieite::types::List<Type>);
```
