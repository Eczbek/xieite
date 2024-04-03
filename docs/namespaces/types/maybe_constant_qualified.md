# [xieite](../../xieite.md)\:\:[types](../../types.md)\:\:MaybeConstantQualified
Defined in header [<xieite/types/maybe_constant_qualified.hpp>](../../../include/xieite/types/maybe_constant_qualified.hpp)

&nbsp;

## Description
An alias to an optionally const-qualified member function pointer type.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Function_, bool constantQualified_>
using MaybeConstantQualified = /* ... */;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/types/maybe_constant_qualified.hpp"
#include "xieite/types/name.hpp"

struct Foo {
    void bar() volatile && noexcept;
};

int main() {
    using Function = decltype(&Foo::bar);

    std::println("{}", xieite::types::name<xieite::types::MaybeConstantQualified<Function, true>>);
    std::println("{}", xieite::types::name<xieite::types::MaybeConstantQualified<Function, false>>);
}
```
Possible output:
```
void (Foo::*)() const volatile && noexcept
void (Foo::*)() volatile && noexcept
```
