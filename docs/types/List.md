# [xieite](../xieite.md)\:\:[types](../types.md)\:\:List
Defined in header [<xieite/types/List.hpp>](../../include/xieite/types/List.hpp)

&nbsp;

## Description
A simple class for storing a list of types.

&nbsp;

## Synopses
#### 1)
```cpp
template<typename... Types>
struct List {
    using Data = std::tuple<Types...>;

    template<typename Type>
    constexpr std::conditional_t<(std::same_as<Types, Type> || ...), xieite::types::List<Types...>, xieite::types::List<Types..., Type>> operator->*(xieite::types::List<Type>) const;
};
```
##### Member types
- [Data](./List/Data.md)
##### Member functions
- [operator->*](./List/operatorMemberPointer.md)
