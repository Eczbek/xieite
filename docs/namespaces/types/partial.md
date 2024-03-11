# [xieite](../../xieite.md)\:\:[types](../../types.md)\:\:Partial
Defined in header [<xieite/types/partial.hpp>](../../../include/xieite/types/partial.hpp)

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
##### Members
- [Append](./structures/partial/1/append.md)
- [Prepend](./structures/partial/1/prepend.md)
