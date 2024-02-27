# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:DerivedFromAny
Defined in header [<xieite/concepts/derived_from_any.hpp>](../../../include/xieite/concepts/derived_from_any.hpp)

&nbsp;

## Description
Specifies that a type is derived from at least one of several other types. Passing no base types evaluates to `true`.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Derived, typename... Bases>
concept DerivedFromAny = (... || std::derived_from<Derived, Bases>);
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/concepts/derived_from_all.hpp"

struct Foo {};

struct Bar {};

struct Baz
: Foo {};

struct Qux
: Bar {};

template<xieite::concepts::DerivedFromAny<Foo, Bar>>
void test() {
    std::println("yep");
}

template<typename>
void test() {
    std::println("nope");
}

int main() {
    test<Baz>();
    test<Qux>();
}
```
Output:
```
yep
yep
```
