# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:ConstantInvocable\<\>
Defined in header [<xieite/concepts/constant_invocable.hpp>](../../../include/xieite/concepts/constant_invocable.hpp)

&nbsp;

## Description
Specifies that a functor type is invocable without mutating.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Functor, typename... Arguments>
concept ConstantInvocable = /* ... */;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/concepts/constant_invocable.hpp"

struct Foo {
    void operator()() const {}
};

struct Bar {
    void operator()() {}
};

int main() {
    std::println("{}", xieite::concepts::ConstantInvocable<Foo>);
    std::println("{}", xieite::concepts::ConstantInvocable<Bar>);
}
```
Output:
```
true
false
```
