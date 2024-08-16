# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:InvocableWithArity\<\>
Defined in header [<xieite/concepts/invocable_with_arity.hpp>](../../../include/xieite/concepts/invocable_with_arity.hpp)

&nbsp;

## Description
Specifies that a functor can be invoked with a specific number of arguments without throwing exceptions.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Functor, std::size_t arity>
concept InvocableWithArity = /* ... */;
```

&nbsp;

## Example
```cpp
#include <print>
#include <stdexcept>
#include "xieite/concepts/invocable_with_arity.hpp"

int main() {
    auto foo = [](int) -> void {};

    auto bar = [](int, int, int) -> void {};

    std::println("{}", xieite::concepts::InvocableWithArity<decltype(foo), 3>);
    std::println("{}", xieite::concepts::InvocableWithArity<decltype(bar), 3>);
}
```
Output:
```
false
true
```
