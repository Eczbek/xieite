# [xieite](../../../../../xieite.md)\:\:[types](../../../../../types.md)\:\:[List<Types...>](../../../list.md)\:\:Unique\<\>
Defined in fragment [xieite:types.List](../../../../../../src/types/list.cpp)

&nbsp;

## Description
Selects one of each type from the stored list of types.

&nbsp;

## Synopsis
#### 1)
```cpp
template<template<typename, typename...> typename Comparator = xieite::traits::IsSameAsAny>
using Unique = /* xieite::types::List<...> */;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    using List = xieite::types::List<int, int, char, int, char>::Unique;

    std::println("{}", xieite::types::name<List>);
}
```
Possible output:
```
xieite::types::List<int, char>
```
