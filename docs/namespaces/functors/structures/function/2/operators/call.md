# [xieite](../../../../../../xieite.md)\:\:[functors](../../../../../../functors.md)\:\:[Function<Return_(Arguments_...)>](../../../../function.md)\:\:operator\(\)\<\>\(\)
Defined in header [<xieite/functors/function.hpp>](../../../../../../../include/xieite/functors/function.hpp)

&nbsp;

## Description
Calls the underlying functor.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename... ArgumentReferences_>
requires((... && std::convertible_to<ArgumentReferences_, Arguments_>))
constexpr Return_ operator()(ArgumentReferences_&&... arguments) const;
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
