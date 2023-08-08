# [xieite](../xieite.md)\:\:[functors](../functors.md)\:\:Arguments
Defined in header [<xieite/functors/Arguments.hpp>](../../include/xieite/functors/Arguments.hpp)

&nbsp;

## Description
Gets the argument types of a functor.

&nbsp;

## Synopsis
```cpp
template<typename Functor>
using Arguments = xieite::types::GetFunctorArguments<decltype(&Functor::operator())>::Type;
```
