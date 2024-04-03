# [xieite](../../xieite.md)\:\:[types](../../types.md)\:\:MaybeRightValueQualified
Defined in header [<xieite/types/maybe_right_value_qualified.hpp>](../../../include/xieite/types/maybe_right_value_qualified.hpp)

&nbsp;

## Description
An alias to an optionally rvalue-qualified member function pointer type.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Function_, bool rightValueQualified_>
using MaybeRightValueQualified = /* ... */;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/types/maybe_right_value_qualified.hpp"
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

    std::println("{}", xieite::types::name<xieite::types::MaybeRightValueQualified<Function1, true>>);
    std::println("{}", xieite::types::name<xieite::types::MaybeRightValueQualified<Function2, true>>);
    std::println("{}", xieite::types::name<xieite::types::MaybeRightValueQualified<Function3, true>>);
    std::println("");
    std::println("{}", xieite::types::name<xieite::types::MaybeRightValueQualified<Function1, false>>);
    std::println("{}", xieite::types::name<xieite::types::MaybeRightValueQualified<Function2, false>>);
    std::println("{}", xieite::types::name<xieite::types::MaybeRightValueQualified<Function3, false>>);
}
```
Possible output:
```
void (Foo::*)() &&
void (Foo::*)()
void (Foo::*)() &&

void (Foo::*)() &
void (Foo::*)() &
void (Foo::*)()
```
