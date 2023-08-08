# [xieite](../xieite.md)\:\:[types](../types.md)\:\:List
Defined in header [<xieite/types/List.hpp>](../../include/xieite/types/List.hpp)

&nbsp;

## Description
A simple class which exists only to store types

&nbsp;

## Synopsis
```cpp
template<typename... Types>
struct List {
    using Data = std::tuple<Types...>;

    template<typename Type>
    constexpr std::conditional_t<(std::same_as<Types, Type> || ...), xieite::types::List<Types...>, xieite::types::List<Types..., Type>> operator->*(xieite::types::List<Type>) const noexcept;
};
```
#### Template parameters
- `Types...` - Any types
#### Public members
## Contents
|- <a href="./List/Data.md">Data</a>
`- <a href="./List/operatorMemberPointer.md">operator->*</a>
