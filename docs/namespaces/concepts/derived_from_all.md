# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:DerivedFromAll
Defined in header [<xieite/concepts/derived_from_all.hpp>](../../../include/xieite/concepts/derived_from_all.hpp)

&nbsp;

## Description
Specifies that a type is derived from several other types. Passing no target types evaluates to `true`.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Derived, typename... Bases>
concept DerivedFromAll = (... && std::derived_from<Derived, Bases>);
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
: Foo, Bar {};

template<xieite::concepts::DerivedFromAll<Foo, Bar>>
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
nope
yep
```
