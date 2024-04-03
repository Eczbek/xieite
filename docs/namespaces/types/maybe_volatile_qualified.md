# [xieite](../../xieite.md)\:\:[types](../../types.md)\:\:MaybeVolatileQualified
Defined in header [<xieite/types/maybe_volatile_qualified.hpp>](../../../include/xieite/types/maybe_volatile_qualified.hpp)

&nbsp;

## Description
An alias to an optionally volatile-qualified member function pointer type.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Function_, bool volatileQualified_>
using MaybeVolatileQualified = /* ... */;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/types/maybe_volatile_qualified.hpp"
#include "xieite/types/name.hpp"

struct Foo {
    void bar() volatile && noexcept;
};

int main() {
    using Function = decltype(&Foo::bar);

    std::println("{}", xieite::types::name<xieite::types::MaybeVolatileQualified<Function, true>>);
    std::println("{}", xieite::types::name<xieite::types::MaybeVolatileQualified<Function, false>>);
}
```
Possible output:
```
void (Foo::*)() const volatile && noexcept
void (Foo::*)() volatile && noexcept
```
