# [xieite](../xieite.md)\:\:[types](../types.md)\:\:PartialBack
Defined in header [<xieite/types/PartialBack.hpp>](../../include/xieite/types/PartialBack.hpp)

&nbsp;

## Description
An intermediate state for a partial specialization.

&nbsp;

## Synopses
#### 1)
```cpp
template<template<typename...> typename Template, typename... BackArguments>
struct PartialBack {
    template<typename... FrontArguments>
    using Type = Template<FrontArguments..., BackArguments...>;
};
```
