# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:TemplateOfAll\<\>
Defined in fragment [xieite:concepts.TemplateOfAll](../../../src/concepts/template_of_all.cpp)

&nbsp;

## Description
Specifies that a template corresponds to all possible specializations of it.

&nbsp;

## Synopsis
#### 1)
```cpp
template<template<typename...> typename Template, typename... Types>
concept TemplateOfAll = (... && xieite::concepts::TemplateOf<Template, Types>);
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
    using Baz = Foo<char>;
    using Qux = Foo<float>;

    std::println("{}", xieite::concepts::TemplateOfAll<Foo, Bar, Baz>);
    std::println("{}", xieite::concepts::TemplateOfAll<Foo, Qux, void>);
}
```
Output:
```
true
false
```
