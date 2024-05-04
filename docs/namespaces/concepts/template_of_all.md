# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:TemplateOfAll\<\>
Defined in header [<xieite/concepts/template_of_all.hpp>](../../../include/xieite/concepts/template_of_all.hpp)

&nbsp;

## Description
Specifies that a template corresponds to all possible specializations of it.

&nbsp;

## Synopsis
#### 1)
```cpp
template<template<typename...> typename Template_, typename... Types>
concept TemplateOfAll = (... && xieite::concepts::TemplateOf<Template_, Types>);
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/concepts/template_of_all.hpp"

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
