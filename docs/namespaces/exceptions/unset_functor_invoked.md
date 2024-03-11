# [xieite](../../xieite.md)\:\:[exceptions](../../exceptions.md)\:\:UnsetFunctorInvoked \{\}
Defined in header [<xieite/exceptions/unset_functor_invoked.hpp>](../../../include/xieite/exceptions/unset_functor_invoked.hpp)

&nbsp;

An exception type that indicates an invocation of a `xieite::functors::Function` that has not been assigned. Extends `xieite::exceptions::Unspecified`.

&nbsp;

## Synopsis
#### 1)
```cpp
struct UnsetFunctorInvoked
: xieite::exceptions::Unspecified {
    UnsetFunctorInvoked(std::string_view = "");
};
```
- [UnsetFunctorInvoked](./structures/unset_functor_invoked/1/operators/constructor.md)

&nbsp;

## Example
```cpp
#include "xieite/exceptions/unset_functor_invoked.hpp"

int main() {
    throw xieite::exceptions::UnsetFunctorInvoked("Something");
}
```
Possible output:
```
terminate called after throwing an instance of 'xieite::exceptions::UnsetFunctorInvoked'
  what():  Something
Aborted (core dumped)
```
