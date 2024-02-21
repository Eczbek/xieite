# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:NoThrowInvocable
Defined in header [<xieite/concepts/no_throw_invocable.hpp"](../../../include/xieite/concepts/no_throw_invocable.hpp)

&nbsp;

## Description
Specifies that a functor can be invoked without throwing exceptions.

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Functor, typename... Arguments>
concept NoThrowInvocable = std::is_nothrow_invocable_v<Functor, Arguments...>;
```

&nbsp;

## Example
```cpp
#include <print>
#include <stdexcept>
#include "xieite/concepts/no_throw_invocable.hpp"

int main() {
    auto lambda = [] {
        throw std::runtime_error("nope");
    };

    std::println("{}", xieite::concepts::NoThrowInvocable<decltype(lambda)>);
}
```
Output:
```
false
```
