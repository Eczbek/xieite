# [xieite](../../../../../../xieite.md)\:\:[functors](../../../../../../functors.md)\:\:[Function<Return(Arguments...)>](../../../../function.md)\:\:operator\(\)
Defined in header [<xieite/functors/function.hpp"](../../../../../../../include/xieite/functors/function.hpp)

&nbsp;

## Description
Calls the underlying functor. Throws `xieite::exceptions::UnsetFunctorInvoked` if the instance was default-constructed and no functor was assigned.

&nbsp;

## Synopses
#### 1)
```cpp
constexpr Return operator()(Arguments... arguments) const;
```
