# [xieite](../../../../../../xieite.md)\:\:[exceptions](../../../../../../exceptions.md)\:\:[UnsetFunctorInvoked](../../../../unset_functor_invoked.md)\:\:UnsetFunctorInvoked
Defined in header [<xieite/exceptions/unset_functor_invoked.hpp>](../../../../../../../include/xieite/exceptions/unset_functor_invoked.hpp)

&nbsp;

Constructs a `xieite::exceptions::UnsetFunctorInvoked`.

## Synopsis
#### 1)
```cpp
UnsetFunctorInvoked(std::string_view message = "") noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/exceptions/unset_functor_invoked.hpp"

int main() {
    xieite::exceptions::UnsetFunctorInvoked exception;

    std::println("{}", exception.what());
}
```
Output:
```

```
