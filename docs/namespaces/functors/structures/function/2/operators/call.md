# [xieite](../../../../../../xieite.md)\:\:[functors](../../../../../../functors.md)\:\:[Function<Return(Arguments...)>](../../../../function.md)\:\:operator()\(\)
Defined in header [<xieite/functors/function.hpp>](../../../../../../../include/xieite/functors/function.hpp)

&nbsp;

## Description
Calls the underlying functor. Throws `xieite::exceptions::UnsetFunctorInvoked` if the instance was default-constructed and no functor was assigned.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename... ArgumentReferences>
requires((... && std::convertible_to<ArgumentReferences, Arguments>))
constexpr Result operator()(ArgumentReferences&&... arguments) const;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/functors/function.hpp"

int main() {
    xieite::functors::Function<void()> foo = [] {
        std::println("Hello, world!");
    };

    foo();
}
```
Output:
```
Hello, world!
```
