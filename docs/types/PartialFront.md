# [xieite](../xieite.md)\:\:[types](../types.md)\:\:PartialFront
Defined in header [<xieite/types/PartialFront.hpp>](../../include/xieite/types/PartialFront.hpp)

&nbsp;

## Description
An intermediate state for a partial specialization.

&nbsp;

## Synopses
#### 1)
```cpp
template<template<typename...> typename Template, typename... FrontArguments>
struct PartialFront {
    template<typename... BackArguments>
    using Type = Template<FrontArguments..., BackArguments...>;
};
```
