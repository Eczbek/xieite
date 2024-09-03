# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:TemplateOfAny\<\>
Defined in fragment [xieite:concepts.TemplateOfAny](../../../src/concepts/template_of_any.cpp)

&nbsp;

## Description
Specifies that a template corresponds to any possible specializations of it.

&nbsp;

## Synopsis
#### 1)
```cpp
template<template<typename...> typename Template, typename... Types>
concept TemplateOfAny = (... || xieite::concepts::TemplateOf<Template, Types>);
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

    std::println("{}", xieite::concepts::TemplateOfAny<Foo, Bar, char>);
    std::println("{}", xieite::concepts::TemplateOfAny<Foo, float, void>);
}
```
Output:
```
true
false
```
