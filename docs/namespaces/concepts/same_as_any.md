# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:SameAsAny\<\>
Defined in header [<xieite/concepts/same_as_any.hpp>](../../../include/xieite/concepts/same_as_any.hpp)

&nbsp;

## Description
Specifies that a type is the same as at least one of several other types. Passing no target types evalutes to `true`.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Source_, typename... Targets_>
concept SameAsAny = (... || std::same_as<Source_, Targets_>);
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/concepts/same_as_any.hpp"

struct Nope {};

template<xieite::concepts::SameAsAny<bool, char, int>>
void test() {
    std::println("yep");
}

template<typename>
void test() {
    std::println("nope");
}

int main() {
    test<char>();
    test<Nope>();
}
```
Output:
```
yep
nope
```
