# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:ConstantExpressionInvocable
Defined in header [<xieite/concepts/constant_expression_invocable.hpp"](../../../include/xieite/concepts/constant_expression_invocable.hpp)

&nbsp;

## Description
Specifies that a functor type is `constexpr`, or that it is invocable during both compile-time and run-time.

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Functor, typename... Arguments>
concept ConstantExpressionInvocable = /* ... */;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/concepts/constant_expression_invocable.hpp"

void foo() {}

constexpr void bar() {}

int main() {
    std::println("{}", xieite::concepts::ConstantExpressionInvocable<foo>);
    std::println("{}", xieite::concepts::ConstantExpressionInvocable<bar>);
}
```
Output:
```
false
true
```
