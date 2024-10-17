# [xieite](../../../../../xieite.md)\:\:[types](../../../../../types.md)\:\:[List<Types...>](../../../list.md)\:\:To\<\>
Defined in fragment [xieite:types.List](../../../../../../src/types/list.cpp)

&nbsp;

## Description
Applies `Types...` to a template.

&nbsp;

## Synopsis
#### 1)
```cpp
template<template<typename...> typename Template>
using To = Template<Types...>;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    using List = xieite::types::List<int, float, char>;

    std::println("{}", xieite::types::name<List::To<std::tuple>>());
}
```
Possible output:
```
std::tuple<int, float, char>
```
