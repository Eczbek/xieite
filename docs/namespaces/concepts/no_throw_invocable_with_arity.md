# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:NoThrowInvocableWithArity\<\>
Defined in header [<xieite/concepts/no_throw_invocable_with_arity.hpp>](../../../include/xieite/concepts/no_throw_invocable_with_arity.hpp)

&nbsp;

## Description
Specifies that a functor can be invoked with a specific number of arguments without throwing exceptions.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Functor_, std::size_t arity_>
concept NoThrowInvocableWithArity = /* ... */;
```

&nbsp;

## Example
```cpp
#include <print>
#include <stdexcept>
#include "xieite/concepts/no_throw_invocable_with_arity.hpp"

int main() {
    auto foo = [](int) noexcept {};

    auto bar = [](int, int, int) noexcept {};

    std::println("{}", xieite::concepts::NoThrowInvocableWithArity<decltype(foo), 3>);
    std::println("{}", xieite::concepts::NoThrowInvocableWithArity<decltype(bar), 3>);
    std::println("{}", xieite::concepts::NoThrowInvocableWithArity<decltype(qux), 3>);
}
```
Output:
```
false
true
false
```
