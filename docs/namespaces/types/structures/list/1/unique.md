# [xieite](../../../../../xieite.md)\:\:[types](../../../../../types.md)\:\:[List<Types_...>](../../../list.md)\:\:Unique\<\>
Defined in header [<xieite/types/list.hpp>](../../../../../../include/xieite/types/list.hpp)

&nbsp;

## Description
Selects one of each type from the stored list of types.

&nbsp;

## Synopsis
#### 1)
```cpp
template<template<typename, typename...> typename Comparator_ = xieite::traits::IsSameAsAny>
using Unique = /* xieite::types::List<...> */;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/types/list.hpp"
#include "xieite/types/name.hpp"

int main() {
    using List = xieite::types::List<int, int, char, int, char>::Unique;

    std::println("{}", xieite::types::name<List>);
}
```
Output:
```
xieite::types::List<int, char>
```
