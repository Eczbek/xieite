# [xieite](../../../../../xieite.md)\:\:[types](../../../../../types.md)\:\:[List<Types_...>](../../../list.md)\:\:Transform\<\>
Defined in header [<xieite/types/list.hpp>](../../../../../../include/xieite/types/list.hpp)

&nbsp;

## Description
Applies a transformation to every set amount of types within the list, in order.

&nbsp;

## Synopsis
#### 1)
```cpp
template<template<typename...> typename Transformer_, std::size_t arguments_>
requires((sizeof...(Types_) % arguments_) == 0)
using Transform = /* xieite::types::List<...> */;
```

&nbsp;

## Example
```cpp
#include <print>
#include <utility>
#include "../xieite/include/xieite/types/list.hpp"
#include "../xieite/include/xieite/types/name.hpp"

int main() {
    using Foo = xieite::types::List<int, char, long, float, short, bool>;

    using Bar = Foo::Transform<std::pair, 2>;

    std::println("{}", xieite::types::name<Bar>);
}
```
Possible output:
```
xieite::types::List<std::pair<int, char>, std::pair<long, float>, std::pair<short, bool>>
```
