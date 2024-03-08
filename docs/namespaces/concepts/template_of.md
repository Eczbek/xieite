# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:TemplateOf
Defined in header [<xieite/concepts/template_of.hpp>](../../../include/xieite/concepts/template_of.hpp)

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
#include <print>
#include "xieite/concepts/template_of.hpp"

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
