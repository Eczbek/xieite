# [xieite](../../xieite.md)\:\:[types](../../types.md)\:\:Partial\<\> \{\}
Defined in fragment [xieite:types.Partial](../../../src/types/partial.cpp)

&nbsp;

## Description
An structure for storing a partial specialization.

&nbsp;

## Synopsis
#### 1)
```cpp
template<template<typename...> typename Template, typename... FirstArguments>
struct Partial {
    template<typename... SecondArguments>
    using Append = Template<FirstArguments..., SecondArguments...>;

    template<typename... SecondArguments>
    using Prepend = Template<SecondArguments..., FirstArguments...>;
};
```
- Append\<\>
- Prepend\<\>

&nbsp;

## Example
```cpp
import std;
import xieite;

template<typename... Types>
struct List {};

int main() {
    using Partial = xieite::types::Partial<List, int, char, bool>;

    std::println("{}", xieite::types::name<Partial::Append<float, double>>());
}
```
Possible output:
```
List<int, char, bool, float, double>
```
