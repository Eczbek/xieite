# [xieite](../../xieite.md)\:\:[types](../../types.md)\:\:Partial
Defined in header [<xieite/types/Partial.hpp>](../../../include/xieite/types/Partial.hpp)

&nbsp;

## Description
An structure for storing a partial specialization.

&nbsp;

## Synopses
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
##### Member types
- [Append](./structures/Partial/1/Append.md)
- [Prepend](./structures/Partial/1/Prepend.md)
