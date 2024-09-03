# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:TemplateOf\<\>
Defined in fragment [xieite:concepts.TemplateOf](../../../src/concepts/template_of.cpp)

&nbsp;

## Description
Specifies that a template corresponds to a possible specialization of it.

&nbsp;

## Synopsis
#### 1)
```cpp
template<template<typename...> typename Template, typename Type>
concept TemplateOf = xieite::concepts::SpecializationOf<Type, Template>;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

template<typename>
struct Foo {};

int main() {
    using Bar = Foo<int>;

    std::println("{}", xieite::concepts::TemplateOf<Foo, Bar>);
    std::println("{}", xieite::concepts::TemplateOf<Bar, char>);
}
```
Output:
```
true
false
```
