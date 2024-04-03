# [xieite](../../xieite.md)\:\:[types](../../types.md)\:\:MaybeLeftValueQualified
Defined in header [<xieite/types/maybe_left_value_qualified.hpp>](../../../include/xieite/types/maybe_left_value_qualified.hpp)

&nbsp;

## Description
An alias to an optionally lvalue-qualified member function pointer type.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Function_, bool leftValueQualified_>
using MaybeLeftValueQualified = /* ... */;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/types/maybe_left_value_qualified.hpp"
#include "xieite/types/name.hpp"

struct Foo {
    void bar();

    void baz() &;

    void qux() &&;
};

int main() {
    using Function1 = decltype(&Foo::bar);
    using Function2 = decltype(&Foo::baz);
    using Function3 = decltype(&Foo::qux);

    std::println("{}", xieite::types::name<xieite::types::MaybeLeftValueQualified<Function1, true>>);
    std::println("{}", xieite::types::name<xieite::types::MaybeLeftValueQualified<Function2, true>>);
    std::println("{}", xieite::types::name<xieite::types::MaybeLeftValueQualified<Function3, true>>);
    std::println("");
    std::println("{}", xieite::types::name<xieite::types::MaybeLeftValueQualified<Function1, false>>);
    std::println("{}", xieite::types::name<xieite::types::MaybeLeftValueQualified<Function2, false>>);
    std::println("{}", xieite::types::name<xieite::types::MaybeLeftValueQualified<Function3, false>>);
}
```
Possible output:
```
void (Foo::*)() &
void (Foo::*)() &
void (Foo::*)()

void (Foo::*)() &&
void (Foo::*)()
void (Foo::*)() &&
```
